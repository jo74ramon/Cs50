#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int greaterLesser (int numbers[]);
int wordCount (string input, int len);
bool getNum (int digit);

int main(int argc, string argv[])
{
    int option;
    if (argc != 2)
    {
        printf("Please type the number of your preferred option\n");
        printf("Choose between the following: \n1 greaterLesser\n2 wordCount\n3 getNum\n");
        do{
            option = get_int("please enter valid option  ");
        }
        while(option < 1 || option > 3);
    }
    else
    {
        option = atoi(argv[1]);
    }


    switch(option)
        {
            case 1:
            {
                printf("\nGreaterLesser\n");
                int numbers[5];
                printf("Please type 5 numbers: \t");
                for(int i=0;i<5;i++)
                {
                    scanf(" %i",&numbers[i]);
                }
                greaterLesser(numbers);
                break;
            }
            case 2:
            {
                int len;
                string input;
                printf("\nwordCount\n");
                do
                {
                    input = get_string("Input up to 20 characters : ");
                    len = strlen(input);
                    if (len > 20)
                    {
                        printf("That's more than 20\n Please. ");

                    }
                }
                while (len > 20);
                wordCount (input, len);
                break;
            }
            case 3:
            {
                int digit = 0;
                printf("\ngetNum\n");
                while (!getNum (digit)) // while getNum isn't true(does not return true), continue looping
                {
                    digit = get_int("Enter one character: ");
                }


            }
            default:
            break;
        }

    }

int greaterLesser(int numbers[])
{
                int largest = 0,smallest;
                smallest = numbers[0];
                for(int i=0, j=0;i<5;i++)
                {
                    if(largest < numbers[i])
                        largest = numbers[i];
                    if(smallest > numbers[i])
                        smallest = numbers[i];
                }
                printf("Largest is %i Smallest is %i\n", largest, smallest);
                return 0;
}

int wordCount (string input, int len)

{
    int a, e, i, o, u = a = e = i = o = 0;

                 for(int j = 0; j <= len; j++)
                    {
                    switch(input[j])
                    {
                        case 'a':
                        case 'A':
                        {
                            a += 1;
                            break;
                        }
                        case 'e':
                        case 'E':
                        {
                            e += 1;
                            break;
                        }
                        case 'i':
                        case 'I':
                        {
                            i += 1;
                            break;
                        }
                        case 'o':
                        case 'O':
                        {
                            o += 1;
                            break;
                        }
                        case 'u':
                        case 'U':
                        {
                            u += 1;
                            break;
                        }
                        default:
                        break;
                    }
                    }
                    printf("a/A appeared %i times\n", a);
                    printf("e/E appeared %i times\n", e);
                    printf("i/I appeared %i times\n", i);
                    printf("o/O appeared %i times\n", o);
                    printf("u/U appeared %i times\n", u);
                    return 0;
}

bool getNum(int digit)
{
    if (digit > 0 && digit < 6)
    {
        return true;
    }
    return false;
}