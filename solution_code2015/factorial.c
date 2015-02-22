#include <stdio.h>

int main() {

    int i;
    scanf("%d", &i);
    int sum = 0;
    int fcur = 1;

    char digits[1000000] = {0};
    digits[0] = 1;


    int max = 1;
    while(sum != i) {
        sum = 0;
        int carry = 0;
        int pos = 0;
        do {
            int mult = digits[pos] * fcur + carry;
            digits[pos] = mult % 10;
            sum += digits[pos];
            carry = mult / 10;
            pos ++;
        } while((pos <= max) | (carry));
        max = pos;
        fcur++;
    }

    printf("%i\n", fcur-1);

    return 1;
}

    
