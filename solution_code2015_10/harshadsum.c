
#include <stdio.h>


int isHarshad(int input);

int main() {
    int input;
    fscanf(stdin, "%d", &input);
    int sum = 0;

    while(input --> 0) {
        if (isHarshad(input+1)) {
            sum += (input+1);
        }
    }
    printf("%i\n", sum);
}


int isHarshad(int input) {
    int copy = input;
    int digisum = 0;
    
    while(copy) {
        digisum += copy%10;
        copy /= 10;
    }

    if (digisum > 0 && input % digisum == 0) {
        return 1;
    } else {
        return 0;
    }
}
