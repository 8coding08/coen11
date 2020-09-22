#include <stdio.h>
int main() {
 int i;
 int score = 0;
 srand ((int) time(NULL));
 for(i = 0; i < 10; i++) {
 int divisor = rand() % 12 + 1;
 int quotient = rand() % 13;
 printf("[#%d] Dividend: %d || Denominator: %d\n", i+1, divisor*quotient, divisor);
 int answer;
 scanf("%d", &answer);
 if(answer == quotient) { 
   score++;
  } else { 
  printf("Incorrect, correct quotient is: %d\n", quotient);
  }
 }
 printf("Your total score is %d/10\n", score);
 return 0;
}
