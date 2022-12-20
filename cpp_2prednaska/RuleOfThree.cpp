#include "Header.h"


// nastavení cstring jako nového pole znakù o délce druhého parametru 
// tvorba nové dynamicky alokované promìnné cstring, 
//		na kterou se budeme odkazovat pointerem cstring
// kterákoli inicializace musí být deklarována za : = inicializaèní èást 
// protože je voláno new, tak je nakonec nutno volat destruktor 
RuleOfThree::RuleOfThree(const char * s, std::size_t length) : cstring(new char[length]) {
	// odkud, kam, kolik 
	// bez 3. parametru - metoda neví, kdy skonèit, 
	//	jestli po 1. prvku, nebo má zkopírovat vše
	std::memcpy(cstring, s, length);
};

// uživateli zjednodušujeme volání kontruktoru 
// implicitní zavolání private konstruktoru deklarovaného døíve
// v parametru už nemohou být jako v .h ' = "" ' - pøekladaè si myslí, že to tam je dvakrát
RuleOfThree::RuleOfThree(const char* s) : RuleOfThree(s, std::strlen(s) + 1) {};

// kopírovací konstrutor 
RuleOfThree::RuleOfThree(const RuleOfThree& another) : RuleOfThree(another.cstring){}

//operátor pøiøazení 
// náležitost tøídì je uvedena pøed operátorem, protože ten jí náleží 
RuleOfThree& RuleOfThree::operator=(const RuleOfThree& other) {
	// kontrola, zda není kopírováno do sebe sama	o1 = o1
	// když je othr pøedáno referencí, jedná se stále pouze o hodnotu  
	// this je pointer, takže je nutno pøed nìj dát *
	// stejné øešení by bylo &other 
	if (this == &other) {
		return *this;
	}
	// za n následuje inicializaèní èást promìnné n
	// n = délka kopírovaného øetìzce 
	std::size_t n{ std::strlen(other.cstring) + 1 };
	// inicializace nového stringu 
	char* new_cstring = new char[n];
	//cstring je pointer na char, který je bez problémù kompatibilní s 
	//	vyžadovaným pointerem na void 
	std::memcpy(new_cstring, other.cstring, n);
	// nutnost vymazat obsah pùvodního cstringu
	delete[] cstring;
	cstring = new_cstring;
	return *this;
}

RuleOfThree::~RuleOfThree() {
	std::cout << "Deleting: " << cstring << std::endl;
	// nutnost zápsu [] za delete, protože tak byla prom. cstring alokována
	// - jako blok charù 
	delete[] cstring;
}

RuleOfThree::operator const char* () const {
	return cstring;
}
