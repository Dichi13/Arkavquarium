#include "LinkedList.h"
#include "AquariumObject.h"
#include "HewanAir.h"
#include <math.h>

HewanAir::HewanAir() {
  hadap_kanan = true;
  direction = 0;
  radius = baseradius;
}

HewanAir::HewanAir(double d, double r) {
  hadap_kanan = true;
  this->setDirection(d);
  this->radius = r;
}

double HewanAir::getDirection() {
  return direction;
}

void HewanAir::setDirection(double d) {
  direction = d;
  if (cos(direction) > 0) {
    hadap_kanan = true;
  } else {
    hadap_kanan = false;
  }
}

bool HewanAir::isHadapKanan(){
	return hadap_kanan;
}

double HewanAir::getRadius(){
	return radius;
}
