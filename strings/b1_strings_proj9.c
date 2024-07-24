#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

int compute_vowel_count(const char *sentence);

int main()
{
    char sentence[MAX_LEN+1];

    printf(": ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("There are %d vowels.\n", compute_vowel_count(sentence));

    return 0;
}

/**
 * @brief This function will sum up the number of vowls from user input
 * 
 * @param sentence A pointer to constant char
 * 
 * @return Return an integer that represents the sum of the number of vowls
 * 
 */
int compute_vowel_count(const char *sentence)
{
    const char *sentence_ptr = sentence;
    int vowel_count = 0;

    while (*sentence_ptr != '\0') {
        switch (toupper(*sentence_ptr++)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowel_count++;
                break;
            default: 
                break;
        }
    }

    return vowel_count;
}