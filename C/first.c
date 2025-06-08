#include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    char str3[100];
    char str4[100] = "HelloWorld";
    char str5[100] = "Hello, C programming is fun!";
    char temp[100];

    // 1. strlen()
    printf("Length of str1: %lu\n", strlen(str1));

    // 2. strcpy()
    strcpy(str3, str1);
    printf("str3 after strcpy: %s\n", str3);

    // 3. strncpy()
    strncpy(temp, str2, 3);
    temp[3] = '\0'; // Add null terminator manually
    printf("First 3 chars of str2 using strncpy: %s\n", temp);

    // 4. strcat()
    strcat(str1, " ");
    strcat(str1, str2);
    printf("str1 after strcat: %s\n", str1);

    // 5. strncat()
    strncat(str3, str2, 3); // append first 3 characters of str2
    printf("str3 after strncat: %s\n", str3);

    // 6. strcmp()
    if (strcmp(str1, str4) == 0)
        printf("str1 and str4 are equal (strcmp)\n");
    else
        printf("str1 and str4 are NOT equal (strcmp)\n");

    // 7. strncmp()
    if (strncmp(str1, str4, 5) == 0)
        printf("First 5 chars of str1 and str4 are equal (strncmp)\n");

    // 8. strchr()
    char *ptr1 = strchr(str1, 'o');
    if (ptr1)
        printf("First occurrence of 'o' in str1: %s\n", ptr1);

    // 9. strrchr()
    char *ptr2 = strrchr(str1, 'o');
    if (ptr2)
        printf("Last occurrence of 'o' in str1: %s\n", ptr2);

    // 10. strstr()
    char *sub = strstr(str5, "programming");
    if (sub)
        printf("Found substring 'programming' in str5: %s\n", sub);

    // 11. strtok()
    printf("Tokens from str5:\n");
    char sentence[100];
    strcpy(sentence, str5);  // strtok modifies the original string
    char *token = strtok(sentence, " ,!");
    while (token != NULL) {
        printf(" - %s\n", token);
        token = strtok(NULL, " ,!");
    }

    return 0;
}
