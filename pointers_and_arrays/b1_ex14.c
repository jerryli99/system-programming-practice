#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DAYS 7
#define HOURS 24

bool search(const int *temperatures, int days, int hours, int key) {
    for (int i = 0; i < days * hours; i++) {
        if (*(temperatures + i) == key) {
            return true;
        }
    }
    return false;
}

int find_largest(const int *a, int n) {
    const int *p = NULL;
    int largest = 0;
    for (p = a; p < a + n; p++) {
        if (*p > largest) {
            largest = *p;
        }
    } 
    return largest;
}

void initialize_temperatures(int *temperatures, int total_elements) {
    // Seed the random number generator
    srand(time(0));

    for (int i = 0; i < total_elements; i++) {
        // Random temperature between -30 and 50 degrees Celsius
        *(temperatures + i) = (rand() % 81) - 30;
    }
}

void print_temperatures(int *temperatures, int days, int hours) {
    printf("Hour:  ");
    for (int j = 0; j < hours; j++) {
        printf("%4d ", j);
    }
    printf("\n");

    for (int i = 0; i < days * hours; i++) {
        if (i % hours == 0) {
            printf("Day %d: ", i / hours + 1);
        }
        printf("%4d ", temperatures[i]);
        if ((i + 1) % hours == 0) {
            printf("\n");
        }
    }
}

int main() {
    int temperature[DAYS][HOURS];
    int total_elements = DAYS * HOURS;
    int largest_temperature = 0;
    int largest_day_temperature = 0;

    initialize_temperatures(temperature[0], total_elements);
    print_temperatures(temperature[0], DAYS, HOURS);
    
    // initialize_temperatures((int *)temperature, total_elements);
    // print_temperatures((int *)temperature, DAYS, HOURS);

    printf("Is there 32? %d\n", search(temperature[0], DAYS, HOURS, 32));

    //find largest in temperatures.
    for (int i = 0; i < DAYS; i++) {
        largest_day_temperature = find_largest(temperature[i], HOURS);
        if (largest_day_temperature > largest_temperature) {
            largest_temperature = largest_day_temperature;
        }
    }

    printf("largest temperature is %d\n", largest_temperature);
    
    return 0;
}


//Notes:
// void init_temperatures(int *temperatures, int days, int hours) {
//     // Seed the random number generator
//     srand(time(0));

//     for (int i = 0; i < days; i++) {
//         for (int j = 0; j < hours; j++) {
//             // Random temperature between -30 and 50 degrees Celsius
//             *(temperatures + i * hours + j) = (rand() % 81) - 30;
//         }
//     }
// }

// void print_temperatures(int *temperatures, int days, int hours) {
//     printf("Hour  ");
//     for (int i = 0; i < hours; i++) {
//         printf("%4d ", i);
//     }
//     printf("\n-----\n");

//     for (int i = 0; i < days; i++) {
//         printf("Day %d: ", i + 1);
//         for (int j = 0; j < hours; j++) {
//             printf("%4d ", *(temperatures + i * hours + j));
//         }
//         printf("\n");
//     }
// }
