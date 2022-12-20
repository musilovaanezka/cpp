#pragma once
#include <string>
#include <iostream>
using namespace std;

// nìco jako interfacy v java 
// obsahují pouze abstraktní metody, které musí být v potomkovi implementovány

class IDriving {
public:
	virtual void accelerate(double kph) = 0;
};

class ISteering {
public:
	virtual void turnLeft(double degrees) = 0;
	virtual void turnRight(double degrees) = 0;
};

class IManufacturer {
public:
	virtual string getManufacturer() = 0;
};

class CWheel {
	string name;
public:
	CWheel(const std::string _name) : name(_name) {};

	// inline funkce - není oddìlena implementace od definice -> narušení zapouzdøení
	void turnLeft(double degrees) { std::cout << name << " Left " << degrees << std::endl; }
	void turnRight(double degrees) { std::cout << name << " Right " << degrees << std::endl; }
	void rotate(double speed) { std::cout << name << "rotating" << speed << std::endl; }
};

class ICar {
private:
	std::string name;
	CWheel* frontLeft;
	CWheel* frontRight;
	CWheel* rearLeft;
	CWheel* rearRight;

	// implementace intefacù
	ISteering* steering;
	IDriving* driving;
	IManufacturer* man;
public:
	CWheel* getFrontLeft() { return frontLeft; }
	CWheel* getFrontRight() { return frontRight; }
	CWheel* getRearLeft() { return rearLeft; }
	CWheel* getRearRight() { return rearRight; }

	void setFrontLeft(CWheel* _frontLeft) { frontLeft = _frontLeft; }
	void setFrontRight(CWheel* _frontRight) { frontRight = _frontRight; }
	void setRearLeft(CWheel* _rearLeft) { rearLeft = _rearLeft; }
	void setRearRight(CWheel* _rearRight) { rearRight = _rearRight; }

	IManufacturer* getManufacturer() { return man; }
	void setManufacturer(IManufacturer* _man) { man = _man; }

	// delegace funkce øízení na tøídu øízení
	ISteering* getSteering() { return steering; }
	void setSteering(ISteering* _steer) { steering = _steer; }
	IDriving* getDriving() { return driving; }
	void setDriving(IDriving* _drive) { driving = _drive; }

	~ICar() {
		std::cout << "CCar will be destucted " << std::endl;
		delete frontLeft;
		delete frontRight;
		delete rearLeft;
		delete rearRight;
		delete steering;
		delete driving;
		delete man;
	}
};


// potomek od Interface
class TwoWheelDrive : public IDriving {
private:
	CWheel* left;
	CWheel* right;
public:
	// konstruktor 
	TwoWheelDrive(CWheel* left, CWheel* right) {
		this->left = left;
		this->right = right;
	}

	// zrycholování dvìma koly 
	void accelerate(double kph) {
		this->left->rotate(kph);
		this->right->rotate(kph);
	}
};

class FrontSteering : public ISteering {
private:
	CWheel* frontLeft;
	CWheel* frontRight;

public:
	//konstruktor
	FrontSteering(CWheel* fl, CWheel* fr) {
		this->frontLeft = fl;
		this->frontRight = fr;
	}
	//zatáèení dvìma koly o poèet stupòù 
	void turnLeft(double degrees) {
		this->frontLeft->turnLeft(degrees);
		this->frontRight->turnLeft(degrees);
	}

	void turnRight(double degrees) {
		this->frontLeft->turnRight(degrees);
		this->frontRight->turnRight(degrees);
	}
};

class Toyota : public IManufacturer {
private: 
	static IManufacturer* instance;
public:
	Toyota() {}

	string getManufacturer() { return "Toyota"; }

	static IManufacturer* getInstance() {
		if (instance == NULL) {
			instance = new Toyota();
		}
		return instance;
	}
};

IManufacturer* Toyota::instance = NULL;

class ToyotaCorolla : public ICar {
public: 
	ToyotaCorolla() {
		this->setFrontLeft(new CWheel("Front left"));
		this->setFrontRight(new CWheel("Front right"));
		this->setRearLeft(new CWheel("Rear left"));
		this->setRearRight(new CWheel("Rear right"));
		this->setSteering(new FrontSteering(this->getFrontLeft(), this->getFrontRight()));
		this->setDriving(new TwoWheelDrive(this->getFrontLeft(), this->getFrontRight()));
		this->setManufacturer(Toyota::getInstance());
	}
};