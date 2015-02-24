#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *values;
int position = 0;

void add(int i) {
	values[position++] = i;
}

void set(int i, int x) {
	values[i] = x;
}

int get(int i) {
	return values[i];
}







int main() {
	int size;
	scanf("%d", &size);	
	values = calloc(size*4, 1);



	add(1);
	int n = 1;

	while(n <= size) {
		int count = 0;
		int plzwork = 1;
		add(0);
		while(plzwork <= n) {
			if (count%4 > 1) {
				set(n, get(n) - get(n-plzwork));
			} else {
				set(n, get(n) + get(n-plzwork));
			}
			count++;
			int fin = (count%2==0)?(count/2+1):(-(count/2+1));
			plzwork = fin*(3*fin-1)/2;
		}
		printf("%i\n", get(n));
		n++;
	}
	printf("%i\n", get(n-1));
}





