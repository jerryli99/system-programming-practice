
//I task is to modify this file in Project4.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

int line_len = 0;
int num_words = 0;

struct node 
{
    struct node *next;
    char word_str[];
};

struct node *line = NULL;

/**
 * 
 * @brief Clear the line
 */
void clear_line(void)
{
    struct node *temp;

    while (line != NULL) 
    {
        temp = line;
        line = line->next;
        free(temp);
    }
    line_len = 0;
    num_words = 0;

    return;
}

/**
 * @brief Add the word to the linked list.
 * 
 * @param word a pointer to a constant char.
 * 
 * @return void
 */
void add_word(const char *word)
{
    int word_size = strlen(word) + 1;

    struct node *new_word;
    new_word = malloc(sizeof(struct node) + word_size);
    if (new_word == NULL) 
    {
        printf("Error, malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_word->word_str, word);
    new_word->next = NULL;

    struct node **line_ptr = &line;
    while (*line_ptr != NULL)
    {
        line_ptr = &(*line_ptr)->next;
    }

    *line_ptr = new_word;
    line_len += strlen(word);

    if (num_words > 0)
    {
        line_len++;
    }

    num_words++;

    return;
}


/**
 * @brief calculates the remaining space length.
 * 
 * @return the remaining space.
 */
int space_remaining(void)
{
    return (MAX_LINE_LEN - line_len);
}



/**
 * @brief write the current line with space justification.
 * 
 * @return void.
 */
void write_line(void)
{
    int extra_spaces, spaces_to_insert, index;
    int char_count = 0;
    struct node *entry = line;

    extra_spaces = space_remaining();

    while ((char_count < line_len) && (entry != NULL)) 
    {
        printf("%s", entry->word_str);
        if (num_words > 1) 
        {
            spaces_to_insert = extra_spaces / (num_words - 1);

            for (index = 1; index <= spaces_to_insert + 1; index++)
            {
                putchar(' ');
            }

            extra_spaces = extra_spaces - spaces_to_insert;
        }

        char_count = char_count + strlen(entry->word_str) + 1;
        num_words--;
        entry = entry->next;
    }

    putchar('\n');
    return;
}


/**
 * @brief write the current line without justification. If line is empty, do
 *        nothing.
 * 
 * @return void.
 */
void flush_line(void)
{
    if (line_len > 0) 
    {
        struct node *entry = line;
        int index;

        for (index = 0, entry = line; entry; index++, entry = entry->next) 
        {
            if ((index > 0) && (entry->next != NULL))
            {
                putchar(' ');
            }
            printf("%s ", entry->word_str);
        }
    }
    printf("\n");
    clear_line();
    return;
}