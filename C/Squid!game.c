#include <stdio.h>
#include<string.h>
#include <time.h>
#include <sys/stat.h>
#include <ctype.h> 


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"





int main ()
{
	char quizes [][100] = 
	{  "1. When was the last world cup football games held?: ",
	   "2. Who were the winners of the word cup?:",
		"3. What was the monetary prize given to the winners of the word cup?: ",
      "4. What is the best walk during a wedding: ",
      "5. Which team did Ronaldo the Goat play for during the world cup: ",
      "6. Which team does Jordan Sancho play for: ",
      "7. Who is the coach of Manchester United as of now: ",
      "8. When was the last time Arsenal won the UEFA cup: ",
      "9. Where was the last Afcon cup of African nations held: ",
      "10. Who were the winners of Afcon: "
      };

      
      char answers[][100] = {
		"A. 2020", "B. 2022", "C. 2023", "D. 2024",
	   "A. Qatar", "B. France", "C. Portugal","D. Argentina.",
	   "A. $40 Million", "B. $54 Million ", "C.$42 Million", "D. $89 Million",
      "A. Bridal walk", "B. Michael Jackson walk", "C. Presidential walk", "D. Moonwalk",
      "A. Brazil", "B. Portugal", "C. Argentina", "D. France",
      "A. Manchester United", "B. Chelsea", "C. Arsenal", "D. Bayern Munich",
      "A. Amorim", "B. Pep Guardiola", "C. Mourinho", "D. Arteta",
      "A. 2005", "B. 2010", "C. Never", "D. 1994",
      "A. Cameroon", "B. Ivory Coast", "C. Nigeria", "D. Egypt",
      "A. Senegal", "B. Egypt", "C. Ivory Coast", "D. Nigeria"

	 };


      char Answers[10] = {'B', 'D', 'C', 'A', 'B', 'B', 'A', 'C', 'B', 'C'};
	int NumberofQuestions = sizeof(quizes)/sizeof(quizes[0]);

	char Attempts;
	char name[200];
	int score =0;


    time_t start, end;
    double time_taken;

   

  printf(MAGENTA "Welcom To My Quiz Game\n"RESET);
  printf(CYAN "What's your precious name: " RESET);
  fgets(name,sizeof(name),stdin);
   name[strcspn(name, "\n")] = '\0'; 


   time(&start);
  
for (int i=0; i<NumberofQuestions; i++)
{
      printf("\n" YELLOW "<------------------------- Question ------------------------->\n" RESET);
      printf(CYAN "%s\n"RESET,quizes[i]);
   for(int j=(i*4); j<(i*4)+4; j++)
   {
	printf("%s\n", answers[j]);
   }

while ((getchar()) != '\n');

   printf("Attempts: ");
   scanf(" %c", &Attempts);
   Attempts=toupper(Attempts);


   if (Attempts == Answers[i])
   {
	printf( MAGENTA"Yooh!!, %s! you're such a football enthusiast bro what would you like for a prize man\n"RESET,name);
      score++;
	 printf(GREEN"Score: %d/%d\n"RESET, score, NumberofQuestions);
   }
   else      
   {
	printf( RED "Wrong bro, A pity what country are you from, is there even football in your country\n" RESET);
	printf(RED"Pity score: %d/%d\n"RESET, score,NumberofQuestions);
   }
}
    time(&end);
     time_taken = difftime(end, start);
    
      float percentage = ((float)score / NumberofQuestions) * 100;
    char grade;
    char remark[100];

    if (percentage >= 90) {
        grade = 'A';
        strcpy(remark, "Excellent! You're a Football enthusiast");
    } else if (percentage >= 70) {
        grade = 'B';
        strcpy(remark, "Great job! nikama unajua kukacheza mkuu");
    } else if (percentage >= 50) {
        grade = 'C';
        strcpy(remark, "Fair effort. Jua mpira wewe!");
    } else if (percentage >= 30) {
        grade = 'D';
        strcpy(remark, "Needs improvement. Ndogomothi kabisaa?");
    } else {
        grade = 'F';
        strcpy(remark, "You might be allergic to football ama ni tiktok mzee");
    }

    printf(MAGENTA "\nThanks for playing, %s!\n" RESET, name);
    printf(CYAN "Final Score: %d/%d (%.2f%%)\n" RESET, score, NumberofQuestions, percentage);
    printf(YELLOW "Grade: %c\n" RESET, grade);
    printf(MAGENTA"Time Taken: %.2f seconds\n"RESET, time_taken);
    printf(BLUE "Remark: %s\n" RESET, remark);

    

   FILE *file;
    struct stat st;
    int file_exists = (stat("scores.txt", &st) == 0);

    file = fopen("scores.txt", "a");
    if (file == NULL) {
        printf(RED "Error opening scores file!\n" RESET);
    } else {
        
        if (!file_exists) {
            fprintf(file, "+----------------------+--------+----------+----------+--------+-------------------------------+\n");
            fprintf(file, "| Name                 | Score  | Total    | Percent  | Grade  | Time Taken (seconds)          |\n");
            fprintf(file, "+----------------------+--------+----------+----------+--------+-------------------------------+\n");
        }

        fprintf(file, "| %-20s | %6d | %8d | %7.2f%% |   %c    | %-29.2f |\n",
                name, score, NumberofQuestions, percentage, grade, time_taken);

        fclose(file);
    }
  return 0;
}

