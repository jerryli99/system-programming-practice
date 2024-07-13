#include <stdio.h>

//original textbook program
// int find_largest(int a[], int n) {
//     int i, max;
//     max = a[0];
//     for (i = 1; i < n; i++) {
//         if (a[i] > max) {
//             max = a[i];
//         }
//     }
//     return max;
// }

int find_largest(const int *a, int n) {
    const int *p = a;
    int max = *p;
    
    for (p = a + 1; p < a + n; p++) {
        if (max < *p) {
            max = *p;
        }
    }
    return max;
}


int main() {
    printf("%d\n", find_largest((int[]){1,2,3,4,5,6,7,8,91,0}, 10));
    return 0;
}