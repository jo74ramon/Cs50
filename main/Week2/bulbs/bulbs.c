#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    //takes in the phrase to transform to bulbs
    string message = get_string("insert text: ");
    //loops through phrase
    for (int i = 0; i < strlen(message); i++)
    {
        unsigned char byte = message[i];
        int binary[BITS_IN_BYTE];
        int quotient = byte;
        int remainder;
    //loops through character's value to fill binary array
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            remainder = quotient % 2;
            binary[j] = remainder;
            quotient = quotient / 2;
        }
    //reverses array to proper binary order and executes function
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }
        printf("\n");

    }

    /*

    string message = get_string("insert text: ");
    for (int i = 0; i < strlen(message); i++)
    {
        unsigned char byte = message[i];
        int binary[BITS_IN_BYTE];
        int binary2[BITS_IN_BYTE];
        int quotient = byte;
        int remainder;

        for (int j = 0; j < BITS_IN_BYTE ; j++)
        {
            remainder = quotient % 2;
            binary[7 - j] = remainder;
            quotient = quotient / 2;
            binary2[j] = binary[7 - j];
            print_bulb(binary2[j]);


        }

        printf("\n");


    }*/

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
