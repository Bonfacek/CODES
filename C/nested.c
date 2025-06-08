#include <stdio.h>

int main()
{
	int rows;
	int columns;
	char symbol;


	printf("\n Enter number of rows: ");
	scanf("%d", &rows);

	printf("\nEnter number of columns: ");
	scanf("%d", &columns);

	while (getchar() != '\n');

	printf("\nEnter the symbol you wanna ues: ");
	scanf("%c, %c", &symbol);

for(int i=1; i<=rows; i++)
{
	for (int j=1;j<=columns; j++)
	{
		printf("%c",symbol);
	}
	printf("\n");
}
return 0;
}