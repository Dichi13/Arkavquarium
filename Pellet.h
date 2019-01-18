#ifndef PELLET_H
#define PELLET_H

#include "AquariumObject.h"

const int PelletSpeed = 30;
const int HargaPellet = 1;

class Pellet : public AquariumObject {
	private:
		// Masih kosong
	public:
  	Pellet(float X, float Y);
  	
  	void move(double);
};

#endif
