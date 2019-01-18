#include "Guppy.h"
#include <iostream>

using namespace std;

int main(){
	Guppy G(0,0,0);
	
	cout << "X : " << G.getX() << endl;
	cout << "Y : " << G.getY() << endl;
	cout << "Speed : " << G.getSpeed() << endl;
	cout << "Direction : " << G.getDirection() << endl;
	cout << "Level : " << G.getLevel() << endl;
	cout << "Pellet Count : " << G.getPellet_count() << endl;
	if(G.isHadapKanan()){
		cout << "Hadap Kanan" << endl;
	}
	else{
		cout << "Hadap Kiri" << endl;
	}
	
	cout << "Wander(), Move()" << endl;
	G.wander(100,100);
	G.move(1);
	cout << "X : " << G.getX() << endl;
	cout << "Y : " << G.getY() << endl;
}

