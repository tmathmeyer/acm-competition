#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct large_int {
	char v[MAX];
} lint;

lint *values;
int position = 0;

void make(int i, lint *dest) {
	int c = 0;
	while(i) {
		(dest->v)[c++] = i%10;
		i /= 10;
	}
	while(c < MAX) {
		(dest->v)[c++] = 0;
	}
}

void ins_i(int i) {
	make(i, values+position);
	position++;
}

void ins(lint i) {
	values[position++] = i;
}

void set(int i, lint x) {
	values[i] = x;
}

lint* get(int i) {
	return values + i;
}

void print(lint *a) {
	int start = 0;
	int i = MAX;
	while(i --> 0) {
		if((a->v)[i]) {
			start = 1;
		}
		if (start) {
			printf("%i", (a->v)[i]);
		}
	}
	puts("");
}

void add(lint *a, lint *b, lint *dest) {
	char carry = 0;
	int i = 0;
	for(; i < MAX; i++) {
		char n = (a->v)[i] + (b->v)[i] + carry;
		(dest->v)[i] = n%10;
		carry = n / 10;
	}
}

void subtract(lint *a, lint *b, lint *dest) {
	int i = 0;
	for(; i < MAX; i++) {
		(dest->v)[i] = (a->v)[i] - (b->v)[i];
	}
	for(i = 0; i < MAX; i++) {
		if ((dest->v)[i] < 0) {
			(dest->v)[i] += 10;
			(dest->v)[i+1] -= 1;
		}
	}
}



void mult(int X, lint *dest) {
	char carry = 0;
	int i = 0;
	for(; i < MAX; i++) {
		int n = (dest->v)[i]*X + carry;
		(dest->v)[i] = n%10;
		carry = n / 10;
	}
}

void copy(lint *a, lint *dest) {
	int i = 0;
	for(; i < MAX; i++) {
		(dest->v)[i] = (a->v)[i];
	}
}




int main() {


	
	int size;
	scanf("%d", &size);	
	values = calloc(size*sizeof(lint), 1);



	ins_i(1);
	int n = 1;

	while(n <= size) {
		int count = 0;
		int plzwork = 1;
		ins_i(0);
		while(plzwork <= n) {
			lint temp;
			make(0, &temp);

			if (count%4 > 1) {
				subtract(get(n), get(n-plzwork), &temp);
				//sub
			} else {
				add(get(n), get(n-plzwork), &temp);
				//add
			}

			copy(&temp, get(n));

			count++;
			int fin = (count%2==0)?(count/2+1):(-(count/2+1));
			plzwork = fin*(3*fin-1)/2;
		}
		n++;
	}
	print(get(n-1));
	
}





