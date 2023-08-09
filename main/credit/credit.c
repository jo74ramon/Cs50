#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Declaring prototypes

int everyOther(long creditCard);
int multiplyAdd(int lastDigit);
int numberOfDigits(long creditCard);
bool isAmex(long creditCard, int numDigits);
bool isMasterCard(long creditCard, int numDigits);
bool isVisa(long creditCard, int numDigits);

//main function

int main(void)
{
    long creditCard = get_long("Credit Card: ");
    int sumEveryOther = everyOther(creditCard);
    int numDigits = numberOfDigits(creditCard);
    bool amex = isAmex(creditCard, numDigits);
    bool master = isMasterCard(creditCard, numDigits);
    bool visa = isVisa(creditCard, numDigits);
    if (sumEveryOther % 10 != 0){
        printf("INVALID\n");
        return 0;
    }
    else if(amex == true){
        printf("AMEX\n");
    }
    else if(master == true){
        printf("MASTERCARD\n");
    }
    else if(visa == true){
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
        return 0;
    }

}

//Get the credit card digit amount

int numberOfDigits(long creditCard){
    int count = 0;
    while(creditCard > 0){
        count = count + 1;
        creditCard = creditCard / 10;
    }
    return count;
}

// Sum the multiplied every other product digits

int everyOther(long creditCard){
    int sum = 0;
    bool altDigit = false;
    while (creditCard > 0){
        if (altDigit == true){
             int lastDigit = creditCard % 10;
             int product = multiplyAdd(lastDigit);
             sum = sum + product;
        }
        else{
            int lastDigit = creditCard % 10;
            sum = sum + lastDigit;
        }
        altDigit =  !altDigit;
        creditCard = creditCard /10;
    }
    return sum;
}

int multiplyAdd(int lastDigit){
    int multiply = lastDigit * 2;
    int sum = 0;
    while (multiply > 0){
        int lastDigitMultiply = multiply % 10;
        sum = sum + lastDigitMultiply;
        multiply = multiply / 10;
    }
    return sum;
}

// Determine card type

bool isAmex(long creditCard, int numDigits){
    int first2 = creditCard / pow(10,13);
    if((numDigits == 15) && (first2 == 34 || first2 == 37)){
        return true;
    }
    else{
        return false;
    }

}

bool isMasterCard(long creditCard, int numDigits){
    int first2 = creditCard / pow(10,14);
    if((numDigits == 16) && (first2 > 50 && first2 < 56)){
        return true;
    }
    else{
        return false;
    }

}

bool isVisa(long creditCard, int numDigits){
    if(numDigits == 13){
        int firstDigit = creditCard / pow(10,12);
        if(firstDigit == 4){
            return true;
        }
    }
    else if(numDigits == 16){
        int firstDigit = creditCard / pow(10,15);
        if(firstDigit == 4){
            return true;
        }
    }
    return false;
}

