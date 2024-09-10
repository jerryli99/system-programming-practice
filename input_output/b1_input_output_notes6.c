/*
Modifies a file of part records by setting the quantity on hand to zero for all
records.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part 
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

struct part inventory[MAX_PARTS];
int num_parts;

int main(void)
{
    // FILE *fp1;

    // // Part 1
    // inventory[0].number = 101;
    // strcpy(inventory[0].name, "Widget A");
    // inventory[0].on_hand = 50;

    // // Part 2
    // inventory[1].number = 102;
    // strcpy(inventory[1].name, "Gizmo B");
    // inventory[1].on_hand = 25;

    // // Part 3
    // inventory[2].number = 103;
    // strcpy(inventory[2].name, "Gadget C");
    // inventory[2].on_hand = 10;

    // // Write to file
    // if ((fp1 = fopen("inventory.dat", "w")) == NULL)
    // {
    //     fprintf(stderr, "Cannot open inventory file\n");
    //     exit(EXIT_FAILURE);
    // }

    // fwrite(inventory, sizeof(struct part), 3, fp1);
    // fclose(fp1);

    FILE *fp;
    int index;

    if ((fp = fopen("inventory.dat", "r+")) == NULL)
    {
        fprintf(stderr, "Cannot open inventory file\n");
        exit(EXIT_FAILURE);
    }

    num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
    printf("%d\n", num_parts);
    for (index = 0; index < num_parts; index++)
    {
        inventory[index].on_hand = 0;
    }

    rewind(fp);
    fwrite(inventory, sizeof(struct part), num_parts, fp);
    fclose(fp);
    
    return (0);
}