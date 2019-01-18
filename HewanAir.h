#ifndef HEWANAIR_H
#define HEWANAIR_H

#include "LinkedList.h"
#include "AquariumObject.h"

const double baseradius = 10;

class HewanAir {
  protected:
  	bool hadap_kanan;
	double direction; //Arah gerak dalam radian
	double radius;
	
  public:
  	HewanAir();
  	HewanAir(double direction, double r);
  	
  	//GettsetSetter
  	double getDirection();
  	void setDirection(double);
  	double getRadius();
  	bool isHadapKanan();
		
  	
  	//Bergerak mengejar suatu objek
  	virtual int pursue(List<AquariumObject*>&) = 0;
  	//Mengenai suatu objek lalu "mengonsumsinya" (contoh ikan makan pellet)
  	virtual int consume(List<AquariumObject*>&, int indeks) = 0;
};

#endif
