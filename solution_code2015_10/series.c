#include <stdio.h>
int main() {
    int a=1, b=2, c=3, d=4;
    while(1) {
        int x=(a+b+c+d)%10;
        a=b;b=c;c=d;d=x;
        printf("%i", x);
    }
}
