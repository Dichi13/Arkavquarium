#include "Pellet.h"

Pellet::Pellet(float X, float Y) : AquariumObject(X, Y, PelletSpeed){}
  	
void Pellet::move(double timepassed){
  this->setY(this->getY() + speed*timepassed);  
}

