#ifndef AQUARIUMOBJECT_H
#define AQUARIUMOBJECT_H

#include <math.h>

class AquariumObject {
	protected:
  	float X, Y; // Koordinat objek di akuarium (x,y).
  	double speed;
  
  public:
  	// Konstruktor
  	AquariumObject();
  	AquariumObject(float _x, float _y, double _speed);
  	virtual ~AquariumObject();
  	
  	// Getter dan setter
  	float getX();
  	float getY();
  	float getSpeed();
  	void setX(float);
  	void setY(float);
  	void setSpeed(double);
	
	//Jarak ke object lain
	float distance(AquariumObject* Obj);
	
	//Fungsi untuk menggerakkan objek
    virtual void move(double) = 0;
};

#endif
