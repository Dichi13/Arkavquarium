#include "Piranha.h"
#include <iostream>

using namespace std;

int main(){
	Piranha P(0,0);
	
	cout << "X : " << P.getX() << endl;
	cout << "Y : " << P.getY() << endl;
	cout << "Speed : " << P.getSpeed() << endl;
	cout << "Direction : " << P.getDirection() << endl;
	if(P.isHadapKanan()){
		cout << "Hadap Kanan" << endl;
	}
	else{
		cout << "Hadap Kiri" << endl;
	}
	
	cout << "Wander(), Move()" << endl;
	P.wander(100,100);
	P.move(1);
	cout << "X : " << P.getX() << endl;
	cout << "Y : " << P.getY() << endl;
}

