// Main.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include "Library.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "����˵��Ϊ�˷��㣬�ڴ��ṩ��ɵ������ʽ���������س���" << endl
		<< "3" << endl
		<< "N123; Object - Oriented Programming; Dave Smith; 2009; 3" << endl
		<< "A251; UML Modelling and Design; Barry Arthur; 2005; 1" << endl
		<< "Z001; Practical Guide to STL; John Johnson; 2000; 5" << endl
		<< "3" << endl
		<< "12345; Joe Bloggs; 3; N123; A251; Z001" << endl
		<< "20498; Ales Alexis; 1; Z001" << endl
		<< "19090; Mike Mike; 2; N123; Z001" << endl
		<< "���񲻼��ˣ���" << endl;
	Library a;
	a.display();
	system("pause");
	return 0;
}

