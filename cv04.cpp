#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 10;

	// alokace pole o délce n
	long* pole = (long*)malloc(sizeof(long) * n);

	// naplníme pole
	for (int i = 0; i < n; i++) {
		*(pole + i) = i;
	}

	// alokace nového pole o délce 2n
	long* pole2 = (long*)malloc(sizeof(long) * (2 * n));

	// zkopírování prvkù pùvodního pole do nového - po polovinách 
	for (int i = 0; i < n; i++) {
		*(pole2 + i) = *(pole + i);
	}
	for (int i = 0; i < n; i++) {
		*(pole2 + i + n) = *(pole + i);
	}

	// dealokace pùvodního pole 
	free(pole);

	// uložení nového pole do pùvodního 
	pole = pole2;


	// prohazování prvkù pole od konce
	long* p1 = pole;
	long* p2 = pole + ((2 * n) - 1);
	long a = 0;
	for (int i = 0; i < n; i++) {
		a = *p1;
		*p1 = *p2;
		*p2 = a;

		p1++;
		p2--;
	}

	// vypsání pole 
	printf("\n");
	for (int i = 0; i < (n * 2); i++) {
		printf("%d\n", pole[i]);
	}

	return 0;
}