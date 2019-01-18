#include "Pellet.h"
#include <iostream>

using namespace std;

int main(){
	Pellet P(12, 34);
	
	cout << "X : " << P.getX() << endl;
	cout << "Y : " << P.getY() << endl;
	cout << "Speed : " << P.getSpeed() << endl;
	
	cout << endl;
	
	cout << "Move()" << endl;
	P.move(1);
	cout << "X : " << P.getX() << endl;
	cout << "Y : " << P.getY() << endl;
	
	cout << "SetX(98)" << endl;
	cout << "SetY(76)" << endl;
	cout << "SetSpeed(54)" << endl;
	P.setX(98);
	P.setY(76);
	P.setSpeed(54);
	cout << endl;
	
	cout << "X : " << P.getX() << endl;
	cout << "Y : " << P.getY() << endl;
	cout << "Speed : " << P.getSpeed() << endl;
}
