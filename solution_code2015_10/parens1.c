

#include <stdio.h>

int chars();

int main() {
    int out = chars();

    printf("%i\n", out);
}

int chars() {
    char buftmp[100]; // maximum string size of 100
    char *buf = buftmp;
    fgets(buf, 100, stdin);

    int parens = 0;
    int totals = 0;

    while(buf) {
        switch(*buf) {
            case ')':
                parens--;
                break;
            case '(':
                parens++;
                totals++;
                break;
        }
        if (parens < 0) {
            return -1;
        }
    }
    if (parens > 0) {
        return -1;
    }

    return totals;
}
