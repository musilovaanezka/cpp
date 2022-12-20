// cpp_prednaska3.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

// soubor .h
class Predek {
public: 
	Predek(int a);
	// abstraktní = čistě virtuální metoda
	// virtual int fce(int a) = 0;
	virtual int fce(int a);
private: 
	int b;
protected: 
	float c;
};

class Predek2 {
public: 
	Predek2(float a);
	virtual int fce(int a);
protected:
	float c;
};

// pokud je před identifikátorem předka uveden modifikátor,
//		tak pokud není modifikátor dané složky přísnější,  
//		stane se z modifikátoru dané modifikátor uveden zde 
//		Pokud modifikátor není uveden, je automaticky protected 
//		Pokud je modifikátor public, složkám zůstává (logicky) 
//		jejich původní identifikátor 
class Potomek : virtual public Predek, public Predek2 {
public:
	Potomek(int a, float b);
	virtual int fce(int a);
	// možnost ovlivnění přístupových práv k atributům a metodám předka
	//Predek::b;

	// konflikt jmen 
	const float getC() const;
};

//soubor .cpp

//konstruktor
Potomek::Potomek(int o, float p) : Predek(o), Predek2(p) {
	 
}

// getC()
//float Potomek::getC() const {
	// nastává konflikt - nevím ze kterého předka dané c pochází 
	//		-> v potomkovi jsou teď 2 float c
	// když by bylo definováno i c v potomkovi, potom je automaticky 
	//		voleno c z potomka 
	
	// return c;

	// zabránění konfliktu 
	// return Predek::c + Predek2::c;

// }

#include "header.h"
int main() {
	Command c1;
	Command c2;
	Invoker in;
	in.addCommand(c1);

	return 0;
}