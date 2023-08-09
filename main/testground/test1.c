#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Max
#define MAX_STUDENTS 5
#define MAX_SUBJECTS 4



// Candidates have name, vote count, eliminated status
typedef struct
{
    char *name;
    int id;
    float subjectScores[MAX_SUBJECTS];
    float average;
}
student;

// Array of students
student alumni[MAX_STUDENTS];

// Numbers of students and subjects
int students;
char *subjects[10] = { "math", "lang", "alge", "bioq"};
// Function prototypes

//int printScores(void);


int main(void)
{

    //Populate subjects
    printf("\n");
    for (int i = 0; i < MAX_SUBJECTS; i++)
    {
        printf("%s %12d\n", subjects[i], 10);
    }
    printf("\n");
    char *input = scanf("%s", input);

    do
    {


        scanf("%s", &input);
        if (isdigit(input[0]) == 0)
        {
            printf("\nPlease enter a valid 0-10 digit: ");



        }

    }
    while (isdigit(input[0]) == 0);

}



//  float temp = 0.0;
//             scanf("%f", &temp);
//             if (isdigit(temp) && temp > 0.0 && temp < 10.0)
//             {
//                 alumni[i].subjectScores[j] = temp;
//             }
//             do
//             {
//                 printf("Please enter a valid score: \n");
//                 scanf("%f", &temp);
//             }
//             while (!isdigit(temp) || temp < 0.0 || temp > 10.0);
//             alumni[i].subjectScores[j] = temp;