#include<stdio.h>
#include<ctype.h>
#include<string.h>



#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"



int main ()
{
	char quizes [][100] = 
	{
		"1.When was the last world cup football games held?: ",
	       "2. Who were the winners of the word cup?:",
		 "3. What was the monetary prize given to the winners of the word cup?: "
       };

      char answers[][100] =
	{
		"A. 2020", "B. 2022", "C.2023", "D.2024",
	       "A.Qatar", "B. France", "C.Portugal","D. Argentina.",
		  "A. $40 Million", "B. $54 Million ", "C.$42 Million", "D. $89 Million"
	 };


      char Answers[3] = {'B', 'D', 'C'};
	int NumberofQuestions = sizeof(quizes)/sizeof(quizes[0]);

	char Attempts;
	char name[100];
	int score =0;
  printf( "Welcom To My Quiz Game\n");
  printf("What's your precious name: ");
  fgets(name,sizeof(name),stdin);
   name[strcspn(name, "\n")] = '\0'; 


for (int i=0; i<NumberofQuestions; i++)
{
	printf("\n<------------------------- Question ------------------------->\n");
	printf("%s\n",quizes[i]);
      printf("<---------------?");
   for(int j=(i*4); j<(i*4)+4; j++)
   {
	printf("%s\n", answers[j]);
   }
   printf("Attempts: ");
   scanf("%c", &Attempts);
   scanf("%c");

   Attempts=toupper(Attempts);

   if (Attempts ==answers[i])
   {
	printf("Yooh!! $s you're such a football enthusiast bro what would you like for a prize man\n",name);
      score++;
	 printf("🔥 Score: %d/%d\n", score, numberOfQuestions);
   }
   else
   {
	printf("Wrong bro, A pity what country are you from, is there even football in your country");
	printf("Pity score: %d/%d\n", score,NumberofQuestions\n);
   }
}
 
  printf("\nThanks for playing, %s! Final Score: %d/%d\n", name, score, numberOfQuestions);
return 0;
}