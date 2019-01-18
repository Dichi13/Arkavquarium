#include "Aquarium.h"

// Konstruktor
Aquarium::Aquarium() {
  sizeX = 640;
  sizeY = 480;
  Snail = new Siput(sizeX/2, sizeY-20);
}
Aquarium::Aquarium(int X, int Y) {
  sizeX = X;
  sizeY = Y;
  Snail = new Siput(sizeX/2, sizeY-20);
}

Aquarium::~Aquarium() { }

int Aquarium::getSizeX() {
  return sizeX;
}
int Aquarium::getSizeY() {
  return sizeY;
}

List<AquariumObject*>& Aquarium::getListPiranha() {
  return ikan_piranha;
}
List<AquariumObject*>& Aquarium::getListGuppy() {
  return ikan_guppy;
}
List<AquariumObject*>& Aquarium::getListKoin() {
  return koin;
}
List<AquariumObject*>& Aquarium::getListPellet() {
  return pellet;
}
Siput* Aquarium::getSiput(){
  return Snail;
}

/* METHOD SPESIFIKASI */
// Memasukkan elemen hewan ke linked list bertipe HewanAir.
void Aquarium::addGuppy(Guppy *obj) {
  ikan_guppy.add(obj);
}
void Aquarium::addPiranha(Piranha *obj) {
  ikan_piranha.add(obj);
}
// Memasukkan elemen koin/pelet ke linked list bertipe FallingObject.
void Aquarium::addKoin(Koin *obj) {
  koin.add(obj);
}
void Aquarium::addPellet(Pellet *obj) {
  pellet.add(obj);
}

int Aquarium::updateAquarium(double timePassed){
  //Update Guppy
  int len = ikan_guppy.length();
  for(int i = 0; i < len; i++) {
    if (!((Guppy*)ikan_guppy.get(i))->updateIkan(sizeX, sizeY, pellet, koin, timePassed)) {
      ikan_guppy.removeAt(i);
      i--;
      len = ikan_guppy.length();
    }
  }
  
	//Update Piranha
  len = ikan_piranha.length();
  for(int i = 0; i < len; i++) {
    Piranha *tempP = (Piranha*) ikan_piranha.get(i);
    bool alive = tempP->updateIkan(sizeX, sizeY, ikan_guppy, koin, timePassed);
  	if (!alive) {
      ikan_piranha.remove(ikan_piranha.get(i));
      i--;
      len = ikan_piranha.length();
    }
  }

	//Update Koin
  len = koin.length();
  for(int i = 0; i < len; i++) {
    Koin* tempK = (Koin*) koin.get(i);
    if (tempK->getY() < sizeY) { 
      tempK->move(timePassed);
    }
  }

	//Update Pellet
  len = pellet.length();
  for(int i = 0; i < len; i++) {
    Pellet* tempP = (Pellet*) pellet.get(i);
    if (tempP->getY() < sizeY) {
      tempP->move(timePassed);
    } else {
      pellet.remove(pellet.get(i));
      len = pellet.length();
      i--;
    }
  }

	//Update Siput;
	int moneyget = Snail->updateSiput(koin, timePassed);
	return moneyget;
}
