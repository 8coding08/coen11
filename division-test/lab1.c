/*
Division Test
by Sam
COEN 11
*/

#include <stdio.h>
int main()
{
  //declare vars
  int i;
  int score = 0;
  srand((int)time(NULL));
  //loop 10 times
  for (i = 0; i < 10; i++)
  {
    int divisor = rand() % 12 + 1;
    int quotient = rand() % 13;
    //give the user the numbers to divide
    printf("[#%d] Dividend: %d || Denominator: %d\n", i + 1, divisor * quotient, divisor);
    //prompt the answer
    int answer;
    scanf("%d", &answer);
    //check if the answer is right
    if (answer == quotient)
    {
      //if the score is right, add a point
      score++;
    }
    else
    {
      //if the score is wrong, tell them then give them the correct answer
      printf("Incorrect, correct quotient is: %d\n", quotient);
    }
  }
  //give user their final score
  printf("Your total score is %d/10\n", score);
  return 0;
}
