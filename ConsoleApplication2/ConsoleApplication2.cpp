// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Queu.h"

//#include <fstream>
using namespace std;

int main()
{


	Queue<int>ob;
	Queue<int>ob1;
	ob.push(10);
	ob.push(20);
	ob.push(30);
	//ob.ff();
	ob1 = ob;
	//ob.remove();
	cout << ob1<< endl;
//	ob.push(36);
	//Queue<int>::f();
	
	return 0;
}






	