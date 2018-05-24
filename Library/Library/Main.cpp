// Main.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include "Library.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "灯神说：为了方便，在此提供题干的输入格式（输完请打回车）" << endl
		<< "3" << endl
		<< "N123; Object - Oriented Programming; Dave Smith; 2009; 3" << endl
		<< "A251; UML Modelling and Design; Barry Arthur; 2005; 1" << endl
		<< "Z001; Practical Guide to STL; John Johnson; 2000; 5" << endl
		<< "3" << endl
		<< "12345; Joe Bloggs; 3; N123; A251; Z001" << endl
		<< "20498; Ales Alexis; 1; Z001" << endl
		<< "19090; Mike Mike; 2; N123; Z001" << endl
		<< "灯神不见了（逃" << endl;
	Library a;
	a.display();
	system("pause");
	return 0;
}

