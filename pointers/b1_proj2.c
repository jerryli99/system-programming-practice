#include <stdio.h>

//assume we have this data from somehere...
int departure_hours[] = {8, 9, 11, 12, 14, 15, 19, 21};
int departure_minutes[] = {0, 43, 19, 47, 0, 45, 0, 45};
int arrival_hours[] = {10, 11, 13, 15, 15, 17, 21, 23};
int arrival_minutes[] = {16, 52, 31, 0, 8, 55, 20, 58};

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void) {
    int hour, minute, desired_time, departure_time, arrival_time;
    printf("Please enter a time(hh:mm): ");
    scanf("%2d :%2d", &hour, &minute);

    desired_time = (hour * 60) + minute;
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    printf("Closest departure time:  %d:%.2d, arriving at %d:%.2d\n",
            departure_time / 60, departure_time % 60,
            arrival_time / 60, arrival_time % 60);

        return 0;
}

//hard coded the provided times here.
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
    int num_flights = sizeof(departure_hours) / sizeof(departure_hours[0]);

    int closest_index = 0;
    int min_diff = (departure_hours[0] * 60 + departure_minutes[0]) - desired_time;

    if (min_diff < 0) {
        min_diff = -min_diff;
    }

    for (int i = 1; i < num_flights; i++) {
        int departure_time_minutes = departure_hours[i] * 60 + departure_minutes[i];
        int diff = departure_time_minutes - desired_time;

        if (diff < 0) {
            diff = -diff; //Interesting. I figured to try this negative sign in C without using absolute(..)
        }

        if (diff < min_diff) {
            min_diff = diff;
            closest_index = i;
        }
    }

    *departure_time = departure_hours[closest_index] * 60 + departure_minutes[closest_index];
    *arrival_time = arrival_hours[closest_index] * 60 + arrival_minutes[closest_index];
}