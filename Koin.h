#ifndef KOIN_H
#define KOIN_H

#include "AquariumObject.h"

const int KoinSpeed = 30;

class Koin : public AquariumObject {
	private:
		int value; // Nilai dari koin
	public:
		Koin();
		Koin(float X, float Y, int _value);
		
		//Getter Setter
		int getValue() const;
		void setValue(int val);
		
		void move(double);
};

#endif
