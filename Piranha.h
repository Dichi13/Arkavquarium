#ifndef PIRANHA_H
#define PIRANHA_H

#include "Ikan.h"

const int HargaPiranha = 25;
const double PiranhaRadius = 15;
const double PiranhaSpeed = 100;

class Piranha : public Ikan {
	private:
		
	public:
		// Konstruktor
		Piranha(float _x, float _y);

		/* METHOD SPESIFIKASI */
		int consume(List<AquariumObject*>&, int indeks);
		bool updateIkan(int sizeX, int sizeY, List<AquariumObject*>& food, List<AquariumObject*>& coins, double timePassed);
};

#endif
