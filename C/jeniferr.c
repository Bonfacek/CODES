#include <cstdio>
#include <cstring>


int main()
{
	float phy, bio,chem,math,total;
	float average;
	char name [30];
	char grade;

printf("Enter your name: ");
fgets(name,sizeof(name),stdin);
name[strlen(name)-1]= '\0';

printf("Enter your phy marks: ");
scanf("%f", &phy);

printf("Enter your Bio marks: ");
scanf("%f", &bio);

printf("Enter your chem marks: ");
scanf("%f", &chem);

printf("Enter your math marks: ");
scanf("%f",&math);

total =phy + bio + chem + math;
average = total/4;

printf("\nname:%s\n",name);
printf("\nTotal marks:%.2f\n", total);
printf("\nAverage marks\n:%.2f", average);


if (average >=90)

{
	printf("\nGrade A\n");
}


else if ( average >=70)
{
	printf("\nGrade B\n");
}
else if (average >=60)
{
	printf("\nGrade C");
}
else if (average >=50)
{
	printf("\nGrade D\n");
}
else if (average >=40)
{
	printf("\n Grade E");
}
else if (average <= 39);
{
	printf("\nGrade F\n");
}
return 0;
}
