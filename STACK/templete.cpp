#include <iostream>
using namespace std;
#include "Pair.cpp"

int main()
{

	Pair<Pair<int, int>, int> p2; // yaha pair<t,v> jana tha but hm ne t ke place pr pair<int,int> pass kiye mtlb huaki hmne pair pass kiya t ke place pr
	p2.setY(10);				  // yha hmne p2->y ko set kiya
	Pair<int, int> p4;			  // hamne j0 bhi t ke place pr pass kiya wo pair<int,int> tha usko hmne ak new variable mana p4
	// yaha hmne p4 ke setx ko call kiya similarly set y ke
	p4.setX(5);
	p4.setY(16);
	// ab p2 ke set function me p4 pass kiiya kyu ki p2 sext x only pair lega
	p2.setX(p4);
	/*ab agar muje p2 ke x function me rakhe value chiye to p2.getX().getX() use karu ga.
	--------t---------------------v-------------
			(p2->t)
		 p4->t  p4->v             (p2->v)
	   ((int 5    |  int  16    )-> p4 |  int 10   )| ->p2
	------------------------------- ------------
	*/
	cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;

	///*
	Pair<int, double> p1;
	p1.setX(100.34);
	p1.setY(100.34);

	cout << p1.getX() << " " << p1.getY() << endl;

	/*ab agar muje p2 ke x function me rakhe value chiye to p2.getX().getX() use karu ga.
	--------t---------------------v-------------
			(p2->t)
		 p4->t  p4->v             (p2->v)
	   ((int 90    |  double  86.5    )-> p4 |  int 10   )| ->p2
	------------------------------- ------------
	
	*/
	//*/
	Pair<Pair<double,int>,int> p6;
	p6.setY(10);
	Pair<double,int> p7;
	p7.setX(1.12);
	p7.setY(6);
	p6.setX(p7);
	cout << p6.getX().getX() << " " << p6.getX().getY() << " " << p6.getY() << endl;
	Pair<int,Pair<double,char>> p9;
	p9.setX(55);
	Pair<double,char> p10;
	p10.setX(98.90);
	p10.setY('y');
	p9.setY(p10);
	cout << p9.getX() << " " << p9.getY().getY() << " " << p9.getY().getX()<< endl;
	/*
	Pair<int> p1;
	p1.setX(10);
	p1.setY(20);

	cout << p1.getX() << " " << p1.getY() << endl;

	Pair<double> p2;

	p2.setX(100.34);
	p2.setY(34.21);
	cout << p2.getX() << " " << p2.getY() << endl;

	Pair<char> p3;

	*/
}
