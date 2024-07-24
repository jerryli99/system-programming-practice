/**
 * @brief This program is copied from the textbook, but I do need to do some minor modifications
 * 
 *        Ignore the style
 */
#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;

  //modified
  const char *rank_code[] = {"Two", "Three", "Four", "Five", "Six",
                             "Seven", "Eight", "Nine", "Ten", "Jack",
                             "Queen", "King", "Ace"};

  //modified
  const char *suit_code[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand:\n");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;     /* picks a random suit */
    rank = rand() % NUM_RANKS;     /* picks a random rank */
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf("%s of %s\n", *(rank_code + rank), *(suit_code + suit)); //----> I modified here
    }
  }

  return 0;
}
