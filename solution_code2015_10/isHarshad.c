
#include <stdio.h>

int main() {
    int input;
    fscanf(stdin, "%d", &input);
    int copy = input;
    int digisum = 0;
    
    while(copy) {
        digisum += copy%10;
        copy /= 10;
    }

    if (input % digisum == 0) {
        puts("true");
    } else {
        puts("false");
    }
}
