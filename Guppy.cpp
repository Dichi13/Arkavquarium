#include "Ikan.h"
#include "Guppy.h"
#include "Koin.h"
/* Variable
		int level; // Tahap pertumbuhan
		int pellet_count; // Jumlah pellet yang telah dimakan
		int coin_timer;
		const int coin_timer_threshold;
*/
Guppy::Guppy(double direction, float x, float y) : Ikan(x,y,GuppySpeed,direction,GuppyRadius), coin_timer_threshold(base_coin_threshold){
	level = 1;
	pellet_count = 0;
}

//Getter Setter
int Guppy::getLevel() {
  return level;
}
int Guppy::getPellet_count() {
  return pellet_count;
}
int Guppy::getCoin_timer() {
  return coin_timer;
}
int Guppy::getCoin_timer_threshold() {
  return coin_timer_threshold;
}
void Guppy::setLevel(int _level) {
  level = _level;
}

void Guppy::operator++() {
//increase pellet count by 1
  pellet_count++;
  if ((level == 1 && pellet_count > 5)||(level == 2 && pellet_count > 12)) {
    level ++;
  } 
}

/* METHOD SPESIFIKASI */

int Guppy::consume(List<AquariumObject*>& pellets, int indeks) {
  pellets.removeAt(indeks);
  this->setTimer(0);
  this->setHungry();
  this->operator++();
  return 0;
}

// Tambahan
bool Guppy::updateIkan(int sizeX, int sizeY, List<AquariumObject*>& food, List<AquariumObject*>& coins, double timePassed) {
  bool alive = Ikan::updateIkan(sizeX, sizeY, food,  coins, timePassed);
  if (alive) {
    coin_timer += timePassed;
    if (coin_timer > coin_timer_threshold) {
      coin_timer = 0;
      int coinvalue = level * GuppyCoinValue;
      coins.add(coinDrop(coinvalue));
    }
    
    if (isHungry() && !food.isEmpty()) {
      int closest = pursue(food);
      if (distance(food.get(closest)) < radius) {
		  consume(food, closest);
	  }
    } else {
      wander(sizeX, sizeY);
    }
    move(timePassed);
  }
  return alive;
  
}
