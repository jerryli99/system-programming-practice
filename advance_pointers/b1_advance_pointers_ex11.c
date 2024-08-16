#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int value;
    struct node *next;
};

int count_occurances(const struct node *list, int value) 
{
    const struct node *list_ptr = NULL;
    int count = 0;

    list_ptr = list;

    while (list_ptr != NULL)
    {
        if (list_ptr->value == value)
        {
            count++;
        }
        list_ptr = list_ptr->next;
    } 

    return (count);
}

int main(void) 
{
    // Creating nodes
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));

    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 1;
    third->next = fourth;

    fourth->value = 3;
    fourth->next = NULL;

    // Testing the count_occurances function
    printf("Number of occurrences of 1: %d\n", count_occurances(head, 1)); // Output should be 2
    printf("Number of occurrences of 2: %d\n", count_occurances(head, 2)); // Output should be 1
    printf("Number of occurrences of 3: %d\n", count_occurances(head, 3)); // Output should be 1
    printf("Number of occurrences of 4: %d\n", count_occurances(head, 4)); // Output should be 0

    // Freeing the allocated memory
    free(head);
    free(second);
    free(third);
    free(fourth);

    return (0);
}

/*
output:
Number of occurrences of 1: 2
Number of occurrences of 2: 1
Number of occurrences of 3: 1
Number of occurrences of 4: 0

*/