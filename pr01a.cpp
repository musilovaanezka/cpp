//1. definujeme novou konstantu kv�li error unsafe pro scanf, zat�m pros�m berte jako fakt, vysv�tl�m pozd�ji
#define _CRT_SECURE_NO_WARNINGS   

//2. vlo��me knihovny, kter� obsahuj� n�mi vyu��van� funkce
// pokud bychom to neud�lali, tak by n�m p�eklada� d�val chybu nap�.:
// scanf : identifik�tor se nena�el
#include <stdio.h>

//3. p�iprav�me z�kladn� metodu main, kter� se spust� po �sp�n�m p�ekladu zdrojov�ho k�du
int main() {
	//4. za��tek bloku 
	// funkce getchar a putchar, pro z�kladn� �ten� a z�pis z a na v�stupn� stream (konzoli)

	int c;
	c = getchar();
	putchar(c);

	//4. konec bloku
	printf("\n------------------------\n5. funkce pro formatovane cteni a zapis \n------------------------\n");
	//5. za��tek bloku
	// funkce pro form�tovan� �ten� a z�pis

	// 5.1 printf n�m umo�n� zapisovat na v�stupn� stream. M� dva parametry, prvn� �et�zec n�m ��k� jak bude vypadat form�t v�stupu
	// (v tomto p��pad�, �e se bude vypisovat �et�zec)
	// a druh� parametr je prom�nn�/konstanta, kter� se m� vypsat 
	// �et�zec \n je takzvan� form�tovac� a tento bude jeden z nejpou��van�j��ch a ��k�, �e se m� od��dkovat
	printf("%s", "Ahoj\n");
	//? Um�li byste pou��t printf aby vypsal:
	// Ahoj
	// sve
	// te

	// definice prom�nn�ch i a j, zat�m bez hodnoty.
	// je z�sadn� si pamatovat, �e po deklarace prom�nn� v C a C++ tato nem� implicitn� hodnotu, tedy nap�/ 0.
	int i, j;
	// zkuste nap��klad:
	//	printf("i = %d - j = %d", i, j);
	// v lep��m p��pad dostanete od p�eklada�e "vynad�no", �e pou��v�te neinicializovanou prom�nnou. 
	// na to pros�m d�vejte v C a C++ velik� pozor, C ani C++ neud�l� nic, co mu ne�eknete, aby ud�lalo (inicializace prom�nn�ch, kontrola mez� pol� atd.).
	// d�ky tomu je, ale v porovn�n� s nap�. Java �i C#, extr�mn� rychl� a proto se st�le vyu��v� a je vy�adovan�

	//5.2 form�tovan� �ten� do prom�nn� pomoc� scanf
	printf("zadej dve cisla int \n");
	scanf("%d", &i);
	scanf("%d", &j);
	//5.3 form�tovan� v�pis prom�nn� pomoc� printf
	printf("%d %d \n", j, i);
	printf("i + j = %d \n", i + j);

	//5. konec bloku

	//6. vyhodnocovan� v�razu
	printf("\n------------------------\n6. vyhodnocovani vyrazu \n------------------------\n");
	// v�dy je vyhodnocuje zleva doprava, lze toho vyu��t p�i nap�. kontrole d�len� nulou viz n�e.
	int y = 3;
	int x = 10;
	int z = 10; //pozor na inicializaci
	// d�ky vyhodnocen� zleva doprava nikdy nedojde k d�len� nulou
	if (y != 0 && x / y < z) {
		//pozor takto nebude vypisovat desetinn� ��slo, proto�e prost� vezme obsah adresy,
		// kam se ulo�� x / y a o�ek�v�, �e to je int a vyp�e tedy jen tu ��st
		// co m� odpov�daj�c� po�et bytu
		printf("%d \n", x / y);

		//i s desetinou ��st�
		// je nutn0 i p�etypov�n� y, aby p�eklada� pochopil, �e v�sledek bude desetinn� ��slo
		printf("%.4f \n", x / (float)y);
	}
	else {
		// v C nejsou v�jimky, v�e se d�l� pomoc� n�vratov�ch hodnot funkc� �i pomoc� if a else jako v tomto p��pad�
		// v�jimky najdeme a� v C++
		printf("deleni nulou\n");
	}

	getchar();
	getchar();

}
