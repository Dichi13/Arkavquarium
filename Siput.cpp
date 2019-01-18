#include "Siput.h"
#include <iostream>

Siput::Siput(float _x, float _y) : AquariumObject(_x, _y, SnailSpeed), HewanAir(0, SnailRadius){
  
}
void Siput::move(double timePassed){
  if(this->hadap_kanan){
    this->setX(this->getX() + speed * timePassed);
  }
  else{
    this->setX(this->getX() - speed * timePassed);
  }
}

int Siput::consume(List<AquariumObject*>& coin, int indeks){
  Koin& caught = (Koin&) *coin.get(indeks);
  int coinvalue = caught.getValue();
  coin.remove(coin.get(indeks));
  return coinvalue;
}

int Siput::pursue(List<AquariumObject*>& coin) {
    AquariumObject *p;
    int imin = 0;
    bool ground;
    double minDist = this->distance(coin.get(0));
    ground = coin.get(0)->getY() >= this->getY();
    for(int i = 1; i < coin.length(); i++){
        
        if (this->distance(coin.get(i)) < minDist){
			if(ground){
				if(coin.get(i)->getY() >= this->getY()){
					imin = i;
					minDist = this->distance(coin.get(i));
				}
			} 
			else{
				imin = i;
				minDist = this->distance(coin.get(i));
			}
        }
    }
    p = coin.get(imin);
    if (p->getX() < this->getX()) {
      this->hadap_kanan = false;
    } else {
      this->hadap_kanan = true;
    }
  
  	if (minDist < this->getRadius()) {
      return consume(coin, imin);
    } else {
      return 0;
    }
    
}

int Siput::updateSiput(List<AquariumObject*>& coin, double timePassed) {
  if (!coin.isEmpty()) {
    int moneyget = pursue(coin);
    move(timePassed);
    return moneyget;
  } else {
    return 0;
  }
}
