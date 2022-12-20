#pragma once

#include <iostream>
	
class Wheel {
	std::string name;
public:
	Wheel(const std::string _name) : name(_name) {};

	// inline funkce - není oddìlena implementace od definice -> narušení zapouzdøení
	void turnLeft(double degrees) { std::cout << name << " Left " << degrees << std::endl; }
	void turnRight(double degrees) { std::cout << name << " Right " << degrees << std::endl; }
	void rotate(double speed) { std::cout << name << "rotating" << speed << std::endl; }
};

class CarBase {
private:
	std::string name;
	Wheel* frontLeft = new Wheel("FrontLeft");
	Wheel* frontRight = new Wheel("frontRight");
	Wheel* rearLeft = new Wheel("rearLeft");
	Wheel* rearRight = new Wheel("rearRight");
public: 
	Wheel* getFrontLeft() { return frontLeft; }
	Wheel* getFrontRight() { return frontRight; }
	Wheel* getRearLeft() { return rearLeft; }
	Wheel* getRearRight() { return rearRight; }

	void setFrontLeft(Wheel* _frontLeft) { frontLeft = _frontLeft; }
	void setFrontRight(Wheel* _frontRight) { frontRight = _frontRight; }
	void setRearLeft(Wheel* _rearLeft) { rearLeft = _rearLeft; }
	void setRearRight(Wheel* _rearRight) { rearRight = _rearRight; }

	std::string getName() { return name; };

	virtual void turnLeft() = 0;
	virtual void turnRight() = 0;
	virtual void accelerate(int speed) = 0;

	~CarBase() {
		std::cout << "Base car will be destucted " << std::endl;
		delete frontLeft; 
		delete frontRight; 
		delete rearLeft; 
		delete rearRight; 
	}
};

class Car : public CarBase {
protected:
	Car() {
		this->setFrontLeft(new Wheel("Front left"));
		this->setFrontRight(new Wheel("Front right"));
		this->setRearLeft(new Wheel("Rear left"));
		this->setRearRight(new Wheel("Rear right"));
	}
public:
	void turnLeft(double degrees) {
		this->getFrontLeft()->turnLeft(degrees);
		this->getFrontRight()->turnLeft(degrees);

	}
	void turnRight(double degrees) {
		this->getFrontLeft()->turnRight(degrees);
		this->getFrontRight()->turnRight(degrees);

	}
	virtual void accelerate(double kph) = 0;
};

class FrontWheelCar : public Car {
public: 
	void accelerate(double kph) {
		this->getFrontLeft() -> rotate(kph);
		this->getFrontLeft() -> rotate(kph);
	}
};

class RearWheelCar : public Car {
public:
	void accelerate(double kph) {
		this->getRearLeft()->rotate(kph);
		this->getRearLeft()->rotate(kph);
	}
};

class AllWheelCar : public Car {
public:
	void accelerate(double kph) {
		this->getFrontLeft()->rotate(kph);
		this->getFrontRight()->rotate(kph);
		this->getRearLeft()->rotate(kph);
		this->getRearRight()->rotate(kph);
	}
};

class ToyotaCorolla : public FrontWheelCar {
public:
	std::string getName() {
		return "Toyota";
	}
};

class ToyotaCorollaSports : public RearWheelCar {
public:
	std::string getName() {
		return "Toyota sporty"
	}
};

class MitsubishiTitan : public AllWheelCar {
public:
	std::string getName() {
		return "Mitsubishi";
	}
};