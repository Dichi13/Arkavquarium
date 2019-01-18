#include "AquariumObject.h"

// Konstruktor
AquariumObject::AquariumObject() {
	X = 0;
  	Y = 0;
  	speed = 0;
}
AquariumObject::AquariumObject(float _x, float _y, double _speed) {
	X = _x;
	Y = _y;
	speed = _speed;
}
AquariumObject::~AquariumObject() {
	
}

// Getter dan setter
float AquariumObject::getX() {
	return X;
}
float AquariumObject::getY() {
	return Y;
}
float AquariumObject::getSpeed() {
	return speed;
}
void AquariumObject::setX(float _x) {
	X = _x;
}
void AquariumObject::setY(float _y) {
	Y = _y;
}
void AquariumObject::setSpeed(double _speed) {
	speed = _speed;
}
float AquariumObject::distance(AquariumObject* Obj){
  return (sqrt(fabs(pow(this->getX() - Obj->getX(), 2) + pow(this->getY() - Obj->getY(), 2))));
}
