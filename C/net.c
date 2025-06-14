#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define PACKET_SIZE 64

// Calculate checksum for ICMP headeCCCCCC  C
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    struct sockaddr_in addr;
    struct hostent *h;

    h = gethostbyname(host);
    if (!h) {
        fprintf(stderr, "Could not resolve hostname\n");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr = *(struct in_addr *)h->h_addr;

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("Socket error");
        return 1;
    }

    char packet[PACKET_SIZE];
    struct icmphdr *icmp = (struct icmphdr *)packet;

    memset(packet, 0, PACKET_SIZE);
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->un.echo.id = getpid();
    icmp->un.echo.sequence = 1;
    icmp->checksum = checksum(packet, PACKET_SIZE);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    if (sendto(sock, packet, PACKET_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
        perror("Sendto failed");
        return 1;
    }

    socklen_t len = sizeof(addr);
    if (recvfrom(sock, packet, PACKET_SIZE, 0, (struct sockaddr *)&addr, &len) <= 0) {
        perror("Recvfrom failed");
        return 1;
    }

    gettimeofday(&end, NULL);

    long time_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    printf("Reply from %s: time=%ldms\n", inet_ntoa(addr.sin_addr), time_ms);

    close(sock);
    return 0;
}
