#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
char subjects[MAX_SUBJECTS][10];
// Function prototypes

//int printScores(void);


int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 6)
    {
        printf("Usage: ex2 [student1 student2 ...]\n");
        return 1;
    }
    //Populate subjects
    printf("Enter 4 subject names\n");
    for (int i = 0; i < MAX_SUBJECTS; i++)
    {
        scanf("%s", subjects[i]);

    }

    // Populate array of students and their scores
    students = argc - 1;
    if (students > MAX_STUDENTS)
    {
        printf("Maximum number of students is %i\n", MAX_STUDENTS);
        return 2;
    }


    for (int i = 0; i < students; i++)
    {
        alumni[i].name = argv[i + 1];
        alumni[i].id = 1 + i;
        printf("Please enter scores(0-10) for %s: \n", alumni[i].name);
        printf("\n");
        float total = 0.0;
        for (int j = 0; j < MAX_SUBJECTS; j++ )
        {
            printf("Score for %s: \n", subjects[j]);
            float input;

            do
            {
                scanf("%f", &input);
                if (input > 10 || input < 0)
                {
                    printf("\nPlease enter a valid 0-10 digit: ");

                }

            }
            while (input > 10 || input < 0);
            printf("\n");
            alumni[i].subjectScores[j] = input;
            total += input;
        }
        alumni[i].average = total / 4;
        printf("\n");

    }
    for (int i = 0; i < students; i++)
    {
        printf("%03i  %-11s%15.2f\n", alumni[i].id ,alumni[i].name, alumni[i].average);

    }

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

// while (!isdigit(alumni[i].subjectScores[j])) || alumni[i].subjectScores[j] > 10 || alumni[i].subjectScores[j] < 0);