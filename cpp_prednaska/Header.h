#pragma once

class Pumpkin {
	// p��stupov� pr�va 
		// private 
		// public 
		// protected 
private:
	int weight;
	static int count;
	static int total_weight;
public:
	// ��st za : = inicializa�n� ��st konstruktoru 
	// obvykle se v t�le kontruktoru nevykon�v� v�ce, ne� inicializace prom�nn�ch
	// p�i v�cen�sobn� d�di�nosti 
	//		vol�n� inicializa�n� ��sti prob�h� p�ed vol�n�m t�la konstruktoru
	Pumpkin(int _weight);
	
	//vyu��v� pouze static prom�nn� -> m�la by b�t sama statick� 
	static void display_total();
	void display();

	// getter pro weight
	int getWeight();

	// p�et�ov�n� oper�tor�
	// p�et�ov�n� oper�toru () 
	// -> vol�n� instance t��dy s () == instance t��dy->display() 
	//	-> bude bez parametr�
	void operator()();
	// p�et�en� oper�toru + 
	// prav� strana u + = parametr 
	// chceme, aby se p�i vol�n� do v�hy lev�ho operandu p�i�etla v�ha prav�ho
	// p�ed�n� referenc�
	void operator+(Pumpkin &);
	// dal�� p�et�en�
	// chceme, aby se p�i vol�n� p�i�etla do v�hy lev�ho operandu dan� hodnota
	void operator+(int i);

	//p�ed�en� oper�toru ==
	// chceme porovnat v�hy dvou instanc�
	bool operator==(Pumpkin &);

	// destruktor 
	// v�dy bez parametr� 
	~Pumpkin();
protected: 
};