#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

double compute_average_word_length(const char *sentence);

int main(void) {
    char sentence[MAX_LEN + 1];

    printf("Input: ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("%.2f\n", compute_average_word_length(sentence));

    return 0;
}

/**
 * @brief This function computes the average word length in a sentence.
 * 
 * @param sentence A pointer to constant char.
 * 
 * @return Returns a double type number representing the average word length of the sentence.
 */
double compute_average_word_length(const char *sentence) {
    const char *sentence_ptr = NULL;
    int char_count = 0;
    int word_count = 0;
    double avg_length = 0.0;

    sentence_ptr = sentence;

    //skip white spaces
    while (*sentence_ptr == ' ') {
        sentence_ptr++;
    }

    //since we use fgets, we need to skip the '\n' as well.
    for ( ; *sentence_ptr != '\0' && *sentence_ptr != '\n'; sentence_ptr++) {
        if (*sentence_ptr == ' ') {
            if (*(sentence_ptr - 1) != ' ') {
                word_count++;
            }
            continue;
        }

        if (*(sentence_ptr + 1) == '\n') {
            word_count++;
        }

        char_count++;
    }

    printf("Char count: %d\n", char_count);
    printf("Word count: %d\n", word_count);
    
    if (word_count == 0) {
        return 0;
    }

    avg_length = (((double) char_count) /  word_count);

    return avg_length;
}