#include <stdio.h>

//this is from the question, ignore style
struct {int x, y;} x;
struct {int x, y;} y;

int main() {

    x.x = 10;
    x.y = 20;
    y.x = 30;
    y.y = 40;

    printf("%d %d %d %d\n", x.x, x.y, y.x, y.y);
    return 0;
}