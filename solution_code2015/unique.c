#include <stdio.h>

int main() {
    int cumulative = 0;
    int read = 0;
    while(scanf("%d", &read) == 1) {
        cumulative ^= read;
    }
    printf("%i", cumulative);
}
