#include "Header.h"
#include <iostream>
// :: zde znamená pøíslušnost metody ke tøídì 
 
// nedìlá se kvùli volání pøedkù: 

//Pumpkin::Pumpkin(int _weight) {
//	this->weight = _weight;
//}

int Pumpkin::count = 0;
int Pumpkin::total_weight = 0;

Pumpkin::Pumpkin(int _weight) : weight(_weight) {
	count += 1;
	total_weight += _weight;
}

void Pumpkin::display() {
	std::cout << this->weight << std::endl;
}
// zde není metoda deklarovaná jako statická - .h je hlavnìjší a na tom souboru záleži 
void Pumpkin::display_total() {
	std::cout << "Count:" << count << ", total:" << total_weight << std::endl;
}
//pøetìžování operátoru ()
void Pumpkin::operator()() {
	display();
}
int Pumpkin::getWeight() {
	return weight;
}

void Pumpkin::operator+(Pumpkin& p) {
	weight += p.getWeight();
}
void Pumpkin::operator+(int n) {
	weight += n;
}
// porovnání vah dvou pumpkin
bool Pumpkin::operator==(Pumpkin& pumpkin) {
	return this->weight == pumpkin.weight;
}

Pumpkin::~Pumpkin(){
	std::cout << "Deleting pumpkin with weight: " << weight << std::endl;
	count--;
	total_weight -= weight;
}