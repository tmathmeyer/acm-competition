#include <stdio.h>
#include <stdlib.h>


int calc(int a) {
    unsigned long long *buffer = 
        calloc(a+1, sizeof(unsigned long long));
    buffer[0] = 1;
    buffer[1] = 1;

    for(int c = 2; c <= a; c++) {
        for(int i = 0; i < c; i++) {
            buffer[c] += buffer[i]*buffer[c-i-1];
        }
    }
    return buffer[a];
}

int main() {
    int input;
    scanf("%d", &input);

    printf("\n%i\n", calc(input));
}
