// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*the password contains at least one upper case
letter, one lower case letter, a number, and a symbol*/
bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool checkLow = false;
    bool checkUpp = false;
    bool checkNum = false;
    bool checkSym = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            checkLow = true;
        }
        if (isupper(password[i]))
        {
            checkUpp = true;
        }
        if (isdigit(password[i]))
        {
            checkNum = true;
        }
        if (!isalnum(password[i]))
        {
            checkSym = true;
        }
    }

    if(checkLow == checkUpp == checkNum == checkSym == true)
    {
        return true;
    }

    return false;
}
