#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    //get input
    string text = get_string("Text: ");

    //calculate letters words in text, loop through to look if IS letter
    int letters = 0;
    int sentences = 0;
    int words = 1;

    for (int i = 0; i < strlen(text); i++)
    {



    // if letter, add letter, calc if is letter ( ascii 65-90 and 97-122)
        if (isalpha(text[i]))
        {
            letters++;
        }
        // count words,
        else if (text[i] == ' ') //count a word everytime there is a space plus 1
        {
            words++;
        }
        //count sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') // count a sentence everytime one of these symbols is encountered
        {
            sentences++;
        }

    }
    //calculate average number of letters per 100 words and the average number of sentences within the same range.
    float L = (float)letters / (float) words * 100;
    float S = (float)sentences / (float) words * 100;
    //calculate the reading level of the text using average letters and sentences
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //output reading level as a string ("Grade 1", or "Grade 16+")
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }




}