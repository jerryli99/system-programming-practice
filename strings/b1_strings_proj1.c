/**
 * @brief This program will find the smallest and largest in a series of words. After the user
 *        enters the words, the program will determine which words would come first and last if the
 *        words were listed in dictionary order. The program must stop accepting input when the user 
 *        enters a four-letter word. Assume that no word is more than 20 letters long.
 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 20
#define END_INPUT_STRING_LEN 4

void compare_words(char *smallest_word, 
                   char *largest_word,
                   char *current_word);

void remove_trailing_special_chars(char *string);

int main() {
    char smallest_word[MAX_STRING_LEN + 1];
    char largest_word[MAX_STRING_LEN + 1];
    char current_word[MAX_STRING_LEN + 1];
    
    // Initialize the words with empty strings
    smallest_word[0] = '\0';
    largest_word[0] = '\0';
    
    // Get the first word
    printf("Enter word: ");
    fgets(current_word, MAX_STRING_LEN + 1, stdin);
    
    // Remove trailing special characters including newline
    remove_trailing_special_chars(current_word);

    strcpy(smallest_word, current_word);
    strcpy(largest_word, current_word);
    
    // Continue to get words until a four-letter word is entered
    while (strlen(current_word) != END_INPUT_STRING_LEN) {
        printf("Enter word: ");
        fgets(current_word, sizeof(current_word), stdin);

        // Remove trailing special characters including newline
        remove_trailing_special_chars(current_word);

        compare_words(smallest_word, largest_word, current_word);
    }

    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}

/**
 * @brief This function will comapre the words and update smallest and largest word 
 *        the user have entered.
 * 
 * @param smallest_word A pointer to char.
 * @param largest_word A pointer to char.
 * @param current_word A pointer to char.
 * 
 * @return Return void.
 */
void compare_words(char *smallest_word, 
                   char *largest_word,
                   char *current_word) {

    if (strcmp(current_word, smallest_word) < 0) {
        strcpy(smallest_word, current_word);
    } else if (strcmp(current_word, largest_word) > 0) {
        strcpy(largest_word, current_word);
    } else {
        // nothing to do here when equal
    }
}


/**
 * @brief This function will remove any characters other than alphenumerics, i.e. \t etc..
 * 
 * @param string A pointer to char.
 * 
 * @return Return void.
 */
void remove_trailing_special_chars(char *string) {
    size_t str_len = strlen(string);
    while (str_len > 0 && !isalnum((unsigned char)string[str_len - 1])) {
        string[str_len - 1] = '\0';
        str_len--;
    }
}

//note: I just realized that char can have negative values (i.e. '0xFF', awkward...), 
//so comparing strings is a little tricky.
//I will probably need to rewrite strcmp in a better way. I will first finish this chapter's projects, then do that.
//need to update b1_strings_ex11.c