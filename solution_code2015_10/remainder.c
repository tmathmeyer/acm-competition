#include<stdio.h>

unsigned int linup_bits(unsigned int to, unsigned int align);
int main() {
    unsigned int N, D;
    fscanf(stdin, "%u", &N);
    fscanf(stdin, "%u", &D);
    while(N > D) {
        N ^= linup_bits(N, D);
    }
    printf("%u\n", N);
}


unsigned int linup_bits(unsigned int to, unsigned int align) {
    int t = 0;
    int highest_to = 0;
    int highest_align = 0;

    while(t < 32) {
        if ((1<<t) & to) {
            highest_to = t;
        }
        t++;
    }
    t = 0;
    while(t < 32) {
        if ((1<<t) & align) {
            highest_align = t;
        }
        t++;
    }

    return align << (highest_to-highest_align);
}
