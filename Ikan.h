#ifndef IKAN_H
#define IKAN_H

#include "HewanAir.h"
#include "AquariumObject.h"
#include "Koin.h"

const double FishRadius = 50;
const int baseHungerThreshold = 10;
const int baseDeathThreshold = 20;

class Ikan : public AquariumObject, public HewanAir{
	private:
		bool hungry;
		double timer;
		double timergerak;
		const int hungerTimerThreshold;
		const int deathTimerThreshold;
  	
	public:
		Ikan(double x, double y, double speed, double direction, double radius);
				
		// GETTER & SETTER
		bool isHungry() const;
		double getTimer() const;
		void setHungry();
		void setTimer(double time);
	  
		/* METHOD SPESIFIKASI */
		//bergerak secara acak
		void wander(int sizeX, int sizeY);
		
		//Menjatuhkan Koin
		virtual Koin* coinDrop(int value);
		
		void move(double);
		int pursue(List<AquariumObject*>&);
		virtual int consume(List<AquariumObject*>&, int indeks) = 0;
		bool updateIkan(int sizeX, int sizeY, List<AquariumObject*>& food, List<AquariumObject*>& coins, double timePassed);
};

#endif
