#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

int main(void) {
  time_t T;
  srandom((unsigned) time(&T));

  int randomRank = random()%12 + 1;
  int randomSuit = random()%4;

  char rank[4][5] = {
    "Ace",
    "Jack",
    "Queen",
    "King"
  };

  char suit[4][9] = {
    "Clubs",
    "Diamonds",
    "Heats",
    "Spade"
  };

  char result[5];
  if(randomRank == 1) strcpy(result, rank[0]);
  else if(randomRank > 9) strcpy(result, rank[randomRank - 9]);
  else result[0] = (char)(randomRank + 48);
  // strcpy(result, "" + (char)(randomRank + 48));

  printf("The card you picked is %s of %s\n", result, suit[randomSuit]);

  return 0;
}