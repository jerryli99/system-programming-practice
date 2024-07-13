#include <stdio.h>

//original find_middle from textbook
// int *find_middle(int a[], int n) {
//     return &a[n/2];
// }

int *find_middle(int *a, int n) {
    return ((n / 2) + a);
}


int main() {
    printf("%d\n", *find_middle( (int[]){1,2,3}, 3 ));
    return 0;
}