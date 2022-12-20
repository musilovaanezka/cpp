#include "Header.h"


// nastaven� cstring jako nov�ho pole znak� o d�lce druh�ho parametru 
// tvorba nov� dynamicky alokovan� prom�nn� cstring, 
//		na kterou se budeme odkazovat pointerem cstring
// kter�koli inicializace mus� b�t deklarov�na za : = inicializa�n� ��st 
// proto�e je vol�no new, tak je nakonec nutno volat destruktor 
RuleOfThree::RuleOfThree(const char * s, std::size_t length) : cstring(new char[length]) {
	// odkud, kam, kolik 
	// bez 3. parametru - metoda nev�, kdy skon�it, 
	//	jestli po 1. prvku, nebo m� zkop�rovat v�e
	std::memcpy(cstring, s, length);
};

// u�ivateli zjednodu�ujeme vol�n� kontruktoru 
// implicitn� zavol�n� private konstruktoru deklarovan�ho d��ve
// v parametru u� nemohou b�t jako v .h ' = "" ' - p�eklada� si mysl�, �e to tam je dvakr�t
RuleOfThree::RuleOfThree(const char* s) : RuleOfThree(s, std::strlen(s) + 1) {};

// kop�rovac� konstrutor 
RuleOfThree::RuleOfThree(const RuleOfThree& another) : RuleOfThree(another.cstring){}

//oper�tor p�i�azen� 
// n�le�itost t��d� je uvedena p�ed oper�torem, proto�e ten j� n�le�� 
RuleOfThree& RuleOfThree::operator=(const RuleOfThree& other) {
	// kontrola, zda nen� kop�rov�no do sebe sama	o1 = o1
	// kdy� je othr p�ed�no referenc�, jedn� se st�le pouze o hodnotu  
	// this je pointer, tak�e je nutno p�ed n�j d�t *
	// stejn� �e�en� by bylo &other 
	if (this == &other) {
		return *this;
	}
	// za n n�sleduje inicializa�n� ��st prom�nn� n
	// n = d�lka kop�rovan�ho �et�zce 
	std::size_t n{ std::strlen(other.cstring) + 1 };
	// inicializace nov�ho stringu 
	char* new_cstring = new char[n];
	//cstring je pointer na char, kter� je bez probl�m� kompatibiln� s 
	//	vy�adovan�m pointerem na void 
	std::memcpy(new_cstring, other.cstring, n);
	// nutnost vymazat obsah p�vodn�ho cstringu
	delete[] cstring;
	cstring = new_cstring;
	return *this;
}

RuleOfThree::~RuleOfThree() {
	std::cout << "Deleting: " << cstring << std::endl;
	// nutnost z�psu [] za delete, proto�e tak byla prom. cstring alokov�na
	// - jako blok char� 
	delete[] cstring;
}

RuleOfThree::operator const char* () const {
	return cstring;
}
