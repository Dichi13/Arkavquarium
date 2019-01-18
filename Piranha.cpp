#include "Piranha.h"
#include "Guppy.h"

// Konstruktor
Piranha::Piranha(float _x, float _y) : Ikan(_x, _y, PiranhaSpeed, 0, PiranhaRadius){

}

/* METHOD SPESIFIKASI */
int Piranha::consume(List<AquariumObject*>& guppy, int indeks) {
  Guppy *eaten;
  eaten = (Guppy*) guppy.get(indeks); 
  int coinvalue = ((eaten->getLevel() + 1) * HargaGuppy);
  this->setTimer(0);
  this->setHungry();
  guppy.remove(guppy.get(indeks));
  return coinvalue;
}

bool Piranha::updateIkan(int sizeX, int sizeY, List<AquariumObject*>& food, List<AquariumObject*>& coins, double timePassed) {
  bool alive = Ikan::updateIkan(sizeX, sizeY, food, coins, timePassed);
  
  if (alive) {
    if (isHungry() && !food.isEmpty()) {
      int caught = pursue(food);
      if (distance(food.get(caught)) < radius) {
        int coinvalue = consume(food, caught);
      	coins.add(coinDrop(coinvalue));
      }
    } else {
      wander(sizeX, sizeY);
    }
    move(timePassed);
  }
  return alive;
}

