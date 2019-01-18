#ifndef GUPPY_H
#define GUPPY_H

#include "Ikan.h"

const double GuppySpeed = 70;
const int base_coin_threshold = 10;
const int HargaGuppy = 10;
const int GuppyCoinValue = 4;
const double GuppyRadius = 30;

class Guppy : public Ikan {
	private:
		int level; // Tahap pertumbuhan
		int pellet_count; // Jumlah pellet yang telah dimakan
		double coin_timer;
		const int coin_timer_threshold;
  
	public:
		// Konstruktor
		Guppy(double direction, float x, float y);
	
		//Getter Setter
		int getLevel();
		int getPellet_count();
		int getCoin_timer();
		int getCoin_timer_threshold();
		void setLevel(int _level);
		
		void operator++();//increase pellet count by 1
		/* METHOD SPESIFIKASI */
		// Method untuk menjatuhkan koin
		
		int consume(List<AquariumObject*>&, int indeks);
		bool updateIkan(int sizeX, int sizeY, List<AquariumObject*>& food, List<AquariumObject*>& coins, double timePassed);
};

#endif
