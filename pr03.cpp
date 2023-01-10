#include <stdio.h>

//definice pomoci funkcnich protypu (doporuceno ANSI)
int secti(int a, int b);
float sectifloat(float a, float b);
int konverze(float to_convert);
void prohod(int a, int b);
void prohod2(int* a, int* b);
void print_vysledek(int x, int n);
int main() {
	//1. cast uvod do pointeru
	/*
	float d = 2.1254;
	float *p_d;

	p_d = &d;

	int a;
	int *p_a = &a;
	a = 10;

	printf("d = %f; p_d = %p, *p_d = %f \n", d, p_d, *p_d);
	printf("a = %d; p_a = %p, *p_a = %d \n", a, p_a, *p_a);
	*/
	//2. pouziti pointeru pro nacteni dat z konzole
	/*
	float d;
	float *p_d = &d;

	scanf("%f", &d);
	printf("d = %f; p_d = %p, *p_d = %f \n", d, p_d, *p_d);
	scanf("%f", p_d);
	printf("d = %f; p_d = %p, *p_d = %f \n", d, p_d, *p_d);
	*/
	//POZOR
	/*
	scanf("%f", *p_d);
	printf("d = %f; p_d = %p, *p_d = %f \n", d, p_d, *p_d);
	*/
	//3. funkce 
	/*
	printf("vysledek = %d, vysledek float = %f \n", secti(10,20), sectifloat(10.25,12154.254));
	printf("Konverze = %d\n", konverze(10.25));
	*/
	//4. volani odkazem pomoci pointeru
	/*
	int a = 10;
	int b = 20;
	printf("a = %d, b = %d \n", a, b);
	prohod(a, b);
	printf("a = %d, b = %d \n", a, b);
	prohod2(&a, &b);
	printf("&a = %d, &b = %d \n", a, b);
	*/
	//5. ZADANI SAMOSTATNE PRACE
	/*
	napiste funkci co bude pocitat x^n, kde n i x je parametr funkce.
	zajistete aby slo volat funci z jine funkce (ale pouze z teto funkce)
	*/
	print_vysledek(10, 5);

}

int naentou(int x, int n) {
	return x * n;
}
void print_vysledek(int x, int n) {
	printf("%d", naentou(x, n));
}
int secti(int a, int b) {
	return a + b;
}
float sectifloat(float a, float b) {
	return a + b;
}
int konverze(float to_convert) {
	return to_convert;
}
void prohod(int a, int b) {
	int c = a;
	a = b;
	b = c;
	printf("a' = %d, b' = %d \n", a, b);
}

void prohod2(int* a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
	printf("a' = %d, b' = %d \n", *a, *b);
}