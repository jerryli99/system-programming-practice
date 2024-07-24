/**
 * @brief In the Scribble Crossword Game, players form words using small tiles, each
 *        containing a letter and a face value. The face value varies from one letter
 *        to another, based on the letter's rarity. Here are the face values:
 *        1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ
 */
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

int compute_scrabble_value(const char *word);

const int scrabble_values[26] = {
       //A  B  C  D   E  F  G  H  I  J  K  L  M
         1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
       //N  O  P  Q   R  S  T  U  V  W  X  Y  Z 
         1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

int main(void)
{
    char word[MAX_LEN + 1];
    printf("Enter a word: ");
    scanf("%s", word);
    printf("Scrabble value: %d\n", compute_scrabble_value(word));
    
    return 0;
}


/**
 * @brief This function will compute the value of a word by summing the values of its letters.
 * 
 * @param word A pointer to constant char.
 * 
 * @return Return an integer that represents the sum of the letters in the word.
 */
int compute_scrabble_value(const char *word)
{
    const char *word_ptr = NULL;
    int total = 0;

    word_ptr = word;

    while (*word_ptr != '\0') {
        total = total + scrabble_values[toupper(*word_ptr++) - 'A'];
    }
      
   return total;
}