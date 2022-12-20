#include "compozice.h"

int main() {
	ToyotaCorolla myCorolla;
	myCorolla.getSteering()->turnLeft(300);
	cout << myCorolla.getManufacturer()->getManufacturer() << endl;
	cin.get();
}