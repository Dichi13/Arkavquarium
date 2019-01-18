#include "Ikan.h"
#include <math.h>
#include <cstdlib>

Ikan::Ikan(double x, double y, double speed, double direction, double radius) : AquariumObject(x,y,speed), HewanAir(direction, radius), hungerTimerThreshold(baseHungerThreshold), deathTimerThreshold(baseDeathThreshold) {
  hungry = false;
  timer = 0;
  timergerak = 0;
}

// GETTER & SETTER
bool Ikan::isHungry() const {
  return hungry;
}
double Ikan::getTimer() const {
  return timer;
}
void Ikan::setHungry() {
  hungry = (timer >= hungerTimerThreshold);
}
void Ikan::setTimer(double time) {
  timer = time;
}

/* METHOD SPESIFIKASI */
//Method untuk menjatuhkan koin
Koin* Ikan::coinDrop(int value) {
  Koin *coin = new Koin(this->getX(), this->getY(), value);
  return coin;
}

void Ikan::move(double timepassed) {
  double xmove = cos(direction)*speed*timepassed;
  double ymove = sin(direction)*speed*timepassed;
  this->setY(this->getY()+ymove);
  this->setX(this->getX()+xmove);
}
//bergerak secara acak
void Ikan::wander(int sizeX, int sizeY) {
  if (this->getX() + cos(direction)*speed*(5-timergerak) > sizeX || this->getX() + cos(direction)*speed*(5-timergerak) < 0 ||
		this->getY() + sin(direction)*speed*(5-timergerak) > sizeY || this->getY() + sin(direction)*speed*(5-timergerak) < 0){
	  this->setDirection(this->getDirection()+2);
  } else {
    if (timergerak > 5){
      timergerak = 0;
      this->setDirection(3.1415*cos(timer));
    }
  }
}

int Ikan::pursue(List<AquariumObject*>& food) {
  AquariumObject *p;
  int imin = 0;
  double minDist = this->distance(food.get(0));
  for(int i = 1; i < food.length(); i++){

      if (this->distance(food.get(i)) < minDist){
          imin = i;
          minDist = this->distance(food.get(i));  
      }
  }
  p = food.get(imin);
  setDirection(atan2(p->getY() - this->getY(), p->getX() - this->getX()));
  return imin;
}

bool Ikan::updateIkan(int sizeX, int sizeY, List<AquariumObject*>& food, List<AquariumObject*>& coins, double timePassed) {
  timer += timePassed;
  timergerak += timePassed;
  if (hungry && timer > deathTimerThreshold) {
    return false;
  } else if (!hungry && timer > hungerTimerThreshold) {
  	hungry = true;
  }
  return true;
  
}
