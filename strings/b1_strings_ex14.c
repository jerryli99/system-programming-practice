#include <stdio.h>

//I copied this program from book. It asked me to find the output.

int main() {
    char s[] = "Hsjodi", *p;

    for (p = s; *p; p++) {
        --*p;
        puts(s);
    }
    return 0;
}

/*

Since we always decrement the value by 1, 
1st iteration, H becomes G. 
2nd iteration, s becomes r.
3rd iteration, j becomes i.
4th iteration, o becomes n.
5th iteration, d becomes c.
6th iteration, i becomes h.

so we get: Grinch


*/