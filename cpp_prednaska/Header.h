#pragma once

class Pumpkin {
	// pøístupová práva 
		// private 
		// public 
		// protected 
private:
	int weight;
	static int count;
	static int total_weight;
public:
	// èást za : = inicializaèní èást konstruktoru 
	// obvykle se v tìle kontruktoru nevykonává více, než inicializace promìnných
	// pøi vícenásobné dìdiènosti 
	//		volání inicializaèní èásti probíhá pøed voláním tìla konstruktoru
	Pumpkin(int _weight);
	
	//využívá pouze static promìnné -> mìla by být sama statická 
	static void display_total();
	void display();

	// getter pro weight
	int getWeight();

	// pøetìžování operátorù
	// pøetìžování operátoru () 
	// -> volání instance tøídy s () == instance tøídy->display() 
	//	-> bude bez parametrù
	void operator()();
	// pøetížení operátoru + 
	// pravá strana u + = parametr 
	// chceme, aby se pøi volání do váhy levého operandu pøièetla váha pravého
	// pøedání referencí
	void operator+(Pumpkin &);
	// další pøetížení
	// chceme, aby se pøi volání pøièetla do váhy levého operandu daná hodnota
	void operator+(int i);

	//pøedížení operátoru ==
	// chceme porovnat váhy dvou instancí
	bool operator==(Pumpkin &);

	// destruktor 
	// vždy bez parametrù 
	~Pumpkin();
protected: 
};