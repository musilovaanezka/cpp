#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <process.h>
/* 1. MAKRA */
//1. a bez parametru
#define MAX 1000
#define PI 3.141592
#define DVE_PI (2 * PI)
#define MOD %
#define SOUBOR "c:/program \
 		files/program/data.txt"

// 1.b s parametrem
#define MAXIMUM(a, b)(((a)<(b))?(a):(b))
//1.b zavorkovat !!
#define SQR(x) x * x //chybne
//#define SQR(x) ((x) * (x)) // spravne


/* 2. include */
//#include "soubor"
//vs
//#include <soubor>


/* 3. PODMINENY PREKLAD */
#define PCAT 1
#if PCAT
#include<conio.h>
#else
#include<stdio.h>
#endif

//3. abychom nemuseli nic definovat
#define PCAT2
/* #undef PCAT2 */
#ifdef PCAT2
#include <conio.h>
#else
#include <stdio.h>
#endif

#ifndef PCAT2
#include <stdio.h>
#else
#include <conio.h>
#endif

/* 4. FUNKCE A ALOKACE PAMETI*/
int a = 20;

/* 4.1 FUNKCE*/
void print(int a); //dopredna deklarace

/* 4.2 PAMETOpodVE TRIDY*/
void funkce(void);


int main() {
	// 1. b
	printf("%d\n", MAXIMUM(10, 30));

	//1.b zavorkovat !!
	printf("%d\n", SQR(2 + 3));

	//3. podmineny preklad
#if PCAT
	printf("Debugging .... \n");
#endif

	/* 4. FUNKCE A ALOKACE PAMETI*/
	//4. staticka alokace datová oblast pamìti + Globální promìnné pouze statická alokace
	int a = 10;
	printf("a = %d\n", a); // co se vypise 10 nebo 20?

	/* 4.1 FUNKCE */
	print(a);

	/* 4.2 PAMETOVE TRIDY*/
	funkce();
	funkce();
	funkce();

	system("pause");
	return 0;
}

/* 4.1 FUNKCE - bude hlasit chybu nezna print musime pouzit doprednou deklaraci */
void print(int a) {
	printf("\nprom = %d \n", a); // ktera a to bude?
}



/* 4.2 PAMETOVE TRIDY*/
void funkce(void) {
	int b = 0;
	static int a = 0;
	b++;
	a++;
	printf("a = %d, b = %d \n", a, b);
}
