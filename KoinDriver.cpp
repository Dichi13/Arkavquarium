#include "Koin.h"
#include <iostream>

using namespace std;

int main(){
	Koin K(12, 34, 56);
	
	cout << "X : " << K.getX() << endl;
	cout << "Y : " << K.getY() << endl;
	cout << "Speed : " << K.getSpeed() << endl;
	cout << "Value : " << K.getValue() << endl;
	
	cout << endl;
	
	cout << "Move()" << endl;
	K.move(1);
	cout << "X : " << K.getX() << endl;
	cout << "Y : " << K.getY() << endl;
	
	cout << "SetX(98)" << endl;
	cout << "SetY(76)" << endl;
	cout << "SetSpeed(54)" << endl;
	cout << "SetValue(32)" << endl;
	K.setX(98);
	K.setY(76);
	K.setSpeed(54);
	K.setValue(32);
	cout << endl;
	
	cout << "X : " << K.getX() << endl;
	cout << "Y : " << K.getY() << endl;
	cout << "Speed : " << K.getSpeed() << endl;
	cout << "Value : " << K.getValue() << endl;
}
