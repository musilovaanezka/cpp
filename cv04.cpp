#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 10;

	// alokace pole o d�lce n
	long* pole = (long*)malloc(sizeof(long) * n);

	// napln�me pole
	for (int i = 0; i < n; i++) {
		*(pole + i) = i;
	}

	// alokace nov�ho pole o d�lce 2n
	long* pole2 = (long*)malloc(sizeof(long) * (2 * n));

	// zkop�rov�n� prvk� p�vodn�ho pole do nov�ho - po polovin�ch 
	for (int i = 0; i < n; i++) {
		*(pole2 + i) = *(pole + i);
	}
	for (int i = 0; i < n; i++) {
		*(pole2 + i + n) = *(pole + i);
	}

	// dealokace p�vodn�ho pole 
	free(pole);

	// ulo�en� nov�ho pole do p�vodn�ho 
	pole = pole2;


	// prohazov�n� prvk� pole od konce
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

	// vyps�n� pole 
	printf("\n");
	for (int i = 0; i < (n * 2); i++) {
		printf("%d\n", pole[i]);
	}

	return 0;
}