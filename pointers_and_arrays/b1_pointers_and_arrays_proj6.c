#include <stdio.h>

#define MAX_INPUT_N 10


void quicksort(int *low_ptr, int *high_ptr);
int *split(int *low_ptr, int *high_ptr);


int main(int argc, char *argv[]) {
    int array[MAX_INPUT_N];
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }
    
    for (int input_count = 0; input_count < MAX_INPUT_N; input_count++) {
        if (fscanf(input_file, "%d", &array[input_count]) != 1) {
            fprintf(stderr, "Error reading input file\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }
    }

    fclose(input_file);

    quicksort(array, array + MAX_INPUT_N - 1);

    for (int index = 0; index < MAX_INPUT_N; index++) {
        fprintf(output_file, "%d\n", array[index]);
    }

    fprintf(output_file, "\n");
    fclose(output_file);
    return 0;
}

/**
 * @brief quicksort is a function to sort the array of integers.
 * 
 * @param low_ptr low_ptr is a pointer to the lower end of the array, starting from array[0].
 * @param high_ptr high_ptr is a pointer to the higher end of the array, starting from array[end_index].
 * 
 * @return Return void.
 */
void quicksort(int *low_ptr, int *high_ptr) {
    int *middle_ptr = NULL;
    if (low_ptr >= high_ptr) {
        return;
    }

    middle_ptr = split(low_ptr, high_ptr);
    quicksort(low_ptr, middle_ptr - 1);
    quicksort(middle_ptr + 1, high_ptr);
    return;
}

/**
 * @brief split is a helper function to quicksort(..).
 * 
 * @param low_ptr low_ptr is a pointer to the lower end of the array, starting from array[0].
 * @param high_ptr high_ptr is a pointer to the higher end of the array, starting from array[end_index].
 * 
 * @return Returns a pointer to the new array split position.
 */
int *split(int *low_ptr, int *high_ptr) {
    int part_element = *low_ptr;

    for (;;) {
        while (low_ptr < high_ptr && part_element <= *high_ptr) {
            high_ptr--;
        }

        if (low_ptr >= high_ptr) {
            break;
        }

        *low_ptr++ = *high_ptr;

        while (low_ptr < high_ptr && *low_ptr <= part_element) {
            low_ptr++;
        }

        if (low_ptr >= high_ptr) {
            break;
        }

        *high_ptr-- = *low_ptr;
    }

    *high_ptr = part_element;
    return high_ptr;
}