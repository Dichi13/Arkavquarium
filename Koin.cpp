#include "AquariumObject.h"
#include "Koin.h"

Koin::Koin() : AquariumObject(0, 0, speed) {
    value = 0;
}
Koin::Koin(float X, float Y, int _value) : AquariumObject(X, Y, KoinSpeed) {
    value = _value;
}

int Koin::getValue() const {
    return value;
}
void Koin::setValue(int val) {
    value = val;
}
void Koin::move(double timepassed) {
    setY(getY() + speed*timepassed);
}
