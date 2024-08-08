/*
This is a copy from the book. 

This program is about maintaining a parts database (linked list version)

*/

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL; //points to the first part

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/*
main: prompts the user to enter an operation code,
      then calls a function to perform the requested 
      action. Repeats until the user enters the
      command 'q'. Prints an error message if the user 
      enters an illegal code. 
*/

int main(void) 
{
    char code;

    for (;;) 
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); //skips the end of the line
        
        switch (code) 
        {
        case 'i':
            insert();
            break;
        
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'q':
            return 0;
        default:
            printff("Illegal code\n");
            break;
        } 
        printf("\n");
    }
}

/*
find_part: Looks up a part number in the inventory 
           list. Returns a pointer to the node 
           containing the part numberl if the part
           number is not found, returns NULL.
*/
struct part *find_part(int number) 
{
    struct part *part_ptr = NULL;

    for (part_ptr = inventory; 
        (part_ptr != NULL) && (number > part_ptr->number);
         part_ptr = part_ptr->next);

    if ((part_ptr != NULL) && (number == part_ptr->number))
    {
        return (part_ptr);
    }

    return (NULL);
}

/*
insert: Prompts the user for information about a new
        part and then inserts the part into the 
        inventory list; the list remains sorted by 
        part number. Prints an error message and 
        returns prematurely if the part already exists
        or space could not be allocated for the part.
*/
void insert(void) 
{
    struct part *curr, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (curr = inventory, prev = NULL;
        (curr != NULL) && (new_node->number > curr->number);
         prev = curr, curr = curr->next);

    if ((curr != NULL) && (new_node->number == curr->number))
    {
        printf("Part already exists\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = curr;
    if (prev == NULL)
    {
        inventory = new_node;
    }
    else 
    {
        prev->next = new_node;
    }
    return;
}


/*
 search: Prompts the user to enter a part number, then 
         looks up the part in the database. If the part
         exists, prints the name and quantity on hand;
         if not, prints an error message.
*/
void search(void) {
    int number;
    struct part *part_ptr;

    printf("Enter part number: ");
    scanf("%d", &number);
    part_ptr = find_part(number);

    if (part_ptr != NULL) {
        printf("Part name: %s\n", part_ptr->name);
        printf("Quantity on hand %d\n", part_ptr->on_hand);
    } else {
        printf("Part not found.\n");
    }
    return;
}

/*
 update: Prompts the user to enter a part number.
         Prints an error message if the part doesn't
         exist; otherwise, prompts the user to enter
         change in quantity on hand and updates the
         database.
 */
void update(void) {
    int number, change;
    struct part *part_ptr;

    printf("Enter part number: ");
    scanf("%d", &number);
    part_ptr = find_part(number);

    if (part_ptr != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        part_ptr->on_hand += change;
    } else {
        printf("Part not found.\n");
    }
    return;
}


/*
 print: Prints a listing of all parts in the database,
        showing the part number, part name, and
        quantity on hand. Parts are printed in the
        order in which they were entered into the
        database.
*/
void print(void) {
    struct part *part_ptr;

    printf("Part Number   Part Name                    "
           "Quantuty on Hand\n");
    for (part_ptr = inventory; part_ptr != NULL; part_ptr = part_ptr->next) {
        printf("%7d       %-25s%11d\n", part_ptr->number,
        part_ptr->name, part_ptr->on_hand);
    }
    return;
}


