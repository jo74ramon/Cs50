#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Comparison function for qsort based on digit size
int compare(const void *a, const void *b) {
    int numA = *(int*)a;

    int numB = *(int*)b;
    //printf("%d ", numB);

    int digitsA = countDigits(numA);
    int digitsB = countDigits(numB);

    if (digitsA < digitsB)
        return -1;
    else if (digitsA > digitsB)
        return 1;
    else
        return 0;
}

int main() {

    int numbers[100];
    srand(time(NULL));

    // Generate 100 random numbers from 1 to 500
    for (int i = 0; i < 100; i++) {
        numbers[i] = rand() % 500 + 1;

    }
      


    // Sort the numbers based on digit size
    qsort(numbers, 100, sizeof(int), compare);

    // Print the sorted numbers
    printf("\n\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", numbers[i]);
        if (i % 10 == 0 && i != 0)
        {
         printf("\n");
        }
    }
    printf("\n");

    return 0;
}