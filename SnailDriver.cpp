#include "Siput.h"
#include <iostream>

using namespace std;

int main(){
	Siput S(0,0);
	
	cout << "X : " << S.getX() << endl;
	cout << "Y : " << S.getY() << endl;
	cout << "Speed : " << S.getSpeed() << endl;
	if(S.isHadapKanan()){
		cout << "Hadap Kanan" << endl;
	}
	else{
		cout << "Hadap Kiri" << endl;
	}
	
	out << "Move()" << endl;
	S.move(1);
	cout << "X : " << S.getX() << endl;
	cout << "Y : " << S.getY() << endl;
}

