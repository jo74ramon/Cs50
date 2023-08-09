// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error, incorrect number of arguments\n");
        return 1;
    }
    string word = argv[1];
    string out = replace(word);

    printf( "%s\n", out);


}

/*string replace(string input)
{
    string output = input;
    for (int i = 0; i < strlen(input); i++)
    {
        char c = (input[i]);
        if (c == 'a')
        {
            c = '6';
        }
        else if (c == 'e')
        {
            c = '3';
        }
        else if (c == 'i')
        {
            c = '1';
        }
        else if (c == 'o')
        {
            c = '0';
        }
        //printf("%c\n", input[i]);
        output[i] = c;
       // printf("%c", c);


    }
    //printf("\n");
    printf("%s\n", output);
    return output;


}*/

string replace(string input)
{
    string output = input;
    for (int i = 0; i < strlen(input); i++)
    {
        char c = tolower(input[i]);

        switch (c)
        {
            case 'a':
                output[i] = '6';
                break;

            case 'e':
                output[i] = '3';
                break;

            case 'o':
                output[i] = '0';
                break;

            case 'i':
                output[i] = '1';
                break;

            default:
                output[i] = input[i];
                break;



        }
        //printf("%c\n", input[i]);
        //output[i] = c;
       // printf("%c", c);


    }
    //printf("\n");
    //printf("%s\n", output);
    return output;


}