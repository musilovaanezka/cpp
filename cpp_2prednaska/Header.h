#pragma once
#include <iostream>

class RuleOfThree {


	//private:

	// dynamicky alokovaný øetìzec 
	char* cstring;
	// parametrem je konstrantní pointer
	// v rámci inicializace lze pointer na nìco nastavit, ale dále ho mìnit nelze 
	RuleOfThree(const char *s, std::size_t length);
public:
	// konstruktor 
	// parametrem je konstantní pointer na øetìzec 
	RuleOfThree(const char *s = "");

	// kopírovací konstruktor 
	// jako parametr má sám sebe - adresu na sama sebe 
	RuleOfThree(const RuleOfThree &another);

	// když bychom od tøídy vytváøeli potomky, bylo by nutno deklarovat destruktor 
	// se slovem "virtual" - ekvivalent "abstract" v Javì 
	~RuleOfThree();

	// ekvivalent metody toString()
	// 1. const - návratová hodnota je konstantní øetìzec
	// návratová hodnota = pointer na char 
	// 2. const - metoda nemìní nic ve svém tìle - nenìní žádné parametry tøídy
	//	je takto deklaován kdykoli, kdy nechceme, aby pøi volání této metody byly 
	//	modifikovány parametry tøídy 
	operator const char* () const;

	// operátor pøiøazení "="
	// const nemá velkou váhu prakticky, ale je tím naznaèeno, co nechceme
	//	aby bylo v rámci programu mìnìno 
	// návratovou hodnotou je reference na objekt typu RuloOfThree
	RuleOfThree& operator=(const RuleOfThree& other);
};
