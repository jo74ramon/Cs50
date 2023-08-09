#include <stdlib.h>
#include <stdio.h>

int main(void)
{
int *ptr = malloc(sizeof(int));



   for (int i = 0; i < 197; i++)
   {
         ptr[i] =  i;



        printf("%d  \n", ptr[i]);

   }
printf("%d  \n", ptr[200]);




}