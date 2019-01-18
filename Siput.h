#ifndef SIPUT_H
#define SIPUT_H

#include "HewanAir.h"
#include "AquariumObject.h"
#include "Koin.h"

const double SnailRadius = 30;
const double SnailSpeed = 30;

class Siput : public AquariumObject, public HewanAir {
	private:
		// Masih kosong
	public:
		Siput(float _x, float _y);
		void move(double);

		int consume(List<AquariumObject*>& coin, int indeks);

		int pursue(List<AquariumObject*>& coin);

		int updateSiput(List<AquariumObject*>& coin, double timePassed);
};

#endif
