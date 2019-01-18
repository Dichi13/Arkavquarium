#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "LinkedList.h"
#include "HewanAir.h"
#include "AquariumObject.h"
#include "Ikan.h"
#include "Guppy.h"
#include "Piranha.h"
#include "Koin.h"
#include "Pellet.h"
#include "Siput.h"

class Aquarium {
	private:
		int sizeX, sizeY; // Ukuran akuarium
		List<AquariumObject*> ikan_guppy; // Linked list yang menyimpan objek bertipe Guppy
		List<AquariumObject*> ikan_piranha; // Linked list yang menyimpan objek bertipe Piranha
		List<AquariumObject*> koin; // Linked list yang menyimpan objek bertipe koin
		List<AquariumObject*> pellet; // Linked list yang menyimpan objek bertipe pellet
		Siput *Snail;
	public:
		// Konstruktor
		Aquarium();
		Aquarium(int X, int Y);
		~Aquarium();

		/* METHOD SPESIFIKASI */
		
		//Getter
		int getSizeX();
		int getSizeY();
		List<AquariumObject*>& getListGuppy();
		List<AquariumObject*>& getListPiranha();
		List<AquariumObject*>& getListKoin();
		List<AquariumObject*>& getListPellet();
		Siput* getSiput();
		
		// Memasukkan elemen hewan ke linked list bertipe HewanAir.
		void addGuppy(Guppy *obj);
		void addPiranha(Piranha *obj);
		// Memasukkan elemen koin/pelet ke linked list bertipe FallingObject.
		void addKoin(Koin *obj);
		void addPellet(Pellet *obj);
		
		int updateAquarium(double timePassed);
};

#endif
