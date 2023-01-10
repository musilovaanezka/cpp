#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>

int main() {
	//1. z�pis do souboru
	// zad�n�: nau�te se zapsat 3 hodnoty typu int do souboru
	// deklarujeme prom�nnou typu FILE. Jedn� se pointer (pozn�te d�ky * p�ed n�zvem prom�nn�). Zat�m pros�m berte jako fakt, pointer�m se budeme v�novat hodn�,
	// a studenti je v�t�inou z po��tku moc r�di nemaj�.

	FILE* fw;
	int a, b, c;
	// na�ten� hodnot do prom�nn�ch a, b, c
	printf("Zadej tri int hodnoty oddelene mezerou a stiskni enter \n");
	scanf("%d %d %d", &a, &b, &c);
	// otev�eme soubor (bude otev�en v aktu�ln�m pracovn�m adres��i) v re�imu z�pis ("w")
	fw = fopen("SOUBOR.TXT", "w");
	// zap�eme do souboru na�ten� hodnoty
	fprintf(fw, "%d %d %d \n", a, b, c);
	//zav�eme soubor, je velmi d�le�it� po sob� uklidit. V C a C++ to m��e m�t fat�ln� n�sledky
	fclose(fw);


	//2. p��pis do souboru
	//jedin� z�sadn� zm�na oproti v��e uveden�mu z�pisu do souboru, je re�im otev�en� souboru, tentokr�te "a"
	FILE* fw2;
	int aa, bb, cc;
	printf("Zadej tri int hodnoty oddelene mezerou a stiskni enter \n");
	scanf("%d %d %d", &aa, &bb, &cc);
	fw2 = fopen("SOUBOR.TXT", "a");
	fprintf(fw2, "%d %d %d \n", aa, bb, cc);
	fclose(fw2);

	//3. nacteni ze souboru
	FILE* fr2;
	fr2 = fopen("SOUBOR.TXT", "r");
	//vyu��v�me toho, �e funkce fscanf vrac� EOF, kdy� dojte na konec souboru
	while (fscanf(fr2, "%d %d %d", &a, &b, &c) != EOF)
		printf("%d %d %d \n", a, b, c);
	fclose(fr2);



	//4. cteni cele radky
	 /*
		int c;
		FILE *fr;

		fr = fopen("SOUBOR.TXT", "r");
		while ((c = getc(fr)) != '\n')
			putchar(c);

		putchar('\n');
		fclose(fr);
	*/

	//5. kopirovani souboru
	FILE* fr3, * fw3;
	int ccc;
	/* mus� byt deklarov�na jak int a ne char, proto�e  EOF == -1!!!, tedy je definovan� jako ��slo a ne znak */
	fr3 = fopen("S1.TXT", "r"); //soubor mus� existovat, jinak bude hl�sit chybu. 
	//? Um�li byste toto o�et�it a m�sto chyby napsat u�ivateli, �e soubor neexistuje?
	fw3 = fopen("S2.txt", "w");

	while ((ccc = getc(fr3)) != EOF)
		putc(ccc, fw3);

	fclose(fr3);
	fclose(fw3);


	//6.Co na vstupu to na vystupu 	
	FILE* fw4;
	int cccc;
	fw4 = stdout;
	printf("Napiste text, stisknete '*' pro konec.\n");

	while ((cccc = getchar()) != '*')
		putc(cccc, fw4);

	return 0;

	//7. binarni soubory
	FILE* f;
	int i = 5;
	double d = 3.13345;
	// otev�r�me v re�imu bin�rn�ho �ten� (ji� nebudeme ��st po velikosti char jako v p�edchoz�m p��pad�, ale po velikosti jakou zad�me
	f = fopen("DATA.DAT", "wb+");
	//�teme po tolika bytech, kolik je velikost i, 
	//co� je deklarovan� jako int a tedy �teme jeden int. 
	//Makro sizeof vrac� po�et byte prom�nn� 
	//nebo typu zadan�ho jako parametr
	fwrite(&i, sizeof(i), 1, f);
	fwrite(&d, sizeof(d), 1, f);

	printf("Pozice v souboru je %ld \n", ftell(f));
	fseek(f, 0, SEEK_SET); // posun na za��tek souboru
	i = 0; d = 0.0;
	fread(&i, sizeof(i), 1, f); //zkusit chybu sizeof(d)
	fread(&d, sizeof(d), 1, f);
	printf("Nactena data: i = %d, d = %f \n", i, d);

	fclose(f);
	return 0;

}

