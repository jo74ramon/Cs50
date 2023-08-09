#include <cs50.h>
#include <stdio.h>``

int main(void)
{
//declaring variables
  int height, column, space, row;
//gathering the height
  do
  {
    height = get_int("Positive Number: ");
  }
  while(height > 8||height < 1) ;
//Drawing the hashes
  for (row = 0; row < height; row++)
  {
    for (space = height - 1; space > row; space = space - 1)
    {
      printf(" ");
    }
    for (column = 0; column <= row; column++)
    {
      printf("#");
    }
    printf("\n");
  }
}