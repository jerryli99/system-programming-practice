#include <stdio.h>

int main(void)
{
    int widget = 3;
    printf("%d widget%s\n", widget, widget != 1 ? "s" : "");
    widget = 1;
    printf("%d widget%s\n", widget, widget != 1 ? "s" : "");

    return (0);
}

/*
3 widgets
1 widget
*/