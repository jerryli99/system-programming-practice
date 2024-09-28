/*
The volatile type qualifier

On some computer, certain memory locations are "volatile"; the value stored at
such a location can change as a program is running, even though the program 
itself is not storing ew values there.

*/
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main() {
//     int fd;
//     char buffer[1];

//     fd = open("/dev/tty", O_RDONLY);
//     if (fd == -1) {
//         perror("open");
//         return 1;
//     }

//     while (read(fd, buffer, 1) > 0) {
//         printf("Key pressed: %c\n", buffer[0]);
//     }

//     close(fd);
//     return 0;
// }

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep function

volatile bool flag = false;

void interrupt_service_routine() {
    printf("Flag is being set!\n");
    flag = true; // Set the flag to true
}

//simulates triggering the ISR after a delay
void simulate_external_event() {
    printf("Simulating an external event...\n");
    sleep(2);  // Simulate some delay before the interrupt occurs
    interrupt_service_routine(); // Trigger the ISR
}

int main() {
    printf("Main: Waiting for the flag to be set by ISR...\n");

    // Start a separate thread or process to simulate the external event
    simulate_external_event();

    // Main loop waits for the flag to be set by the ISR
    while (!flag) {
        // Main loop does some work (or waits)
        //sleep(5);
    }

    printf("Main: Flag is set! Exiting loop and finishing program.\n");

    return 0;
}
