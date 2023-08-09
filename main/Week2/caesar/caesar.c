#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//bool only_digits(string x);
//char rotate(char letter, int times);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
        {
        if (!isdigit(argv[1][i]))
            {
            printf("Usage: ./caesar key\n");
            return 1;
            }
        }
    int k = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i <strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            int ascii_offset = isupper(plaintext[i]) ? 65 : 97; //sets the reference value to ascii 65("A") if the char is uppercase or 97("a") if not
            int pi = plaintext[i] - ascii_offset;
            int ci = (pi + k) % 26;
            printf("%c", ci + ascii_offset);
            continue;
         }
         printf("%c", plaintext[i]);



    }
    printf("\n");
    return 0;



}

/*bool only_digits(string x){

}

char rotate(char letter, int times)
{


}*/