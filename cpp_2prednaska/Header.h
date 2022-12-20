#pragma once
#include <iostream>

class RuleOfThree {


	//private:

	// dynamicky alokovan� �et�zec 
	char* cstring;
	// parametrem je konstrantn� pointer
	// v r�mci inicializace lze pointer na n�co nastavit, ale d�le ho m�nit nelze 
	RuleOfThree(const char *s, std::size_t length);
public:
	// konstruktor 
	// parametrem je konstantn� pointer na �et�zec 
	RuleOfThree(const char *s = "");

	// kop�rovac� konstruktor 
	// jako parametr m� s�m sebe - adresu na sama sebe 
	RuleOfThree(const RuleOfThree &another);

	// kdy� bychom od t��dy vytv��eli potomky, bylo by nutno deklarovat destruktor 
	// se slovem "virtual" - ekvivalent "abstract" v Jav� 
	~RuleOfThree();

	// ekvivalent metody toString()
	// 1. const - n�vratov� hodnota je konstantn� �et�zec
	// n�vratov� hodnota = pointer na char 
	// 2. const - metoda nem�n� nic ve sv�m t�le - nen�n� ��dn� parametry t��dy
	//	je takto deklaov�n kdykoli, kdy nechceme, aby p�i vol�n� t�to metody byly 
	//	modifikov�ny parametry t��dy 
	operator const char* () const;

	// oper�tor p�i�azen� "="
	// const nem� velkou v�hu prakticky, ale je t�m nazna�eno, co nechceme
	//	aby bylo v r�mci programu m�n�no 
	// n�vratovou hodnotou je reference na objekt typu RuloOfThree
	RuleOfThree& operator=(const RuleOfThree& other);
};
