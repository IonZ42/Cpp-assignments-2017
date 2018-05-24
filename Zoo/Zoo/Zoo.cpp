#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include"Zoo.h"
using namespace std;

Money::Money(int dollars, int cents)
{
	if (dollars < 0 || cents < 0) { cout << "initialize error!" << endl; d = 0; c = 0; }
	else { d = dollars; c = cents; }
}
Money Money::operator +(const Money right)const
{
	Money temp = *this;
	temp.d += right.d; temp.c += right.c;
	if (temp.c > 99) { temp.d += temp.c / 100; temp.c %= 100; }
	return temp;
}
Money Money::operator +(const double m)const
{
	Money temp = *this;
	temp.d += (int)m; temp.c += (m - (int)m) * 100;
	if (temp.c > 99) { temp.d += temp.c / 100; temp.c %= 100; }
	return temp;
}
Money Money::operator -(const Money right)const
{
	Money temp = *this;
	temp.d -= right.d; temp.c -= right.c;
	if (temp.d < 0 || temp.c < 0) { cout << "subtraction error!nothing will be changed" << endl; temp = *this; }
	if (temp.c > 99) { temp.d += temp.c / 100; temp.c %= 100; }
	return temp;
}
Money Money::operator -(const double m)const
{
	Money temp = *this;
	temp.d -= (int)m; temp.c -= (m - (int)m) * 100;
	if (temp.d < 0 || temp.c < 0) { cout << "subtraction error!nothing will be changed" << endl; temp = *this; }
	if (temp.c > 99) { temp.d += temp.c / 100; temp.c %= 100; }
	return temp;
}

Food::Food(string foodtype, int amount)
{
	if (amount < 0) { cout << "initialize error!" << endl; ft = "NAN"; a = 0; }
	else { ft = foodtype; a = amount; }
}

Enclosure::Enclosure(int dirt_level, bool status)
{
	dl = dirt_level; s = status; cd = 0;
}

Animal::Animal(int amount_of_eaten_food, int food_capacity, double weight)
{
	aef = amount_of_eaten_food; fc = food_capacity; w = weight; e = { 0,1 };
}
void Animal::eat_n_shit(int given_food)
{
	aef += given_food;
	if (aef >= fc) { e.dl += aef; aef = 0; }
}
elephants::elephants(double trunk_length)
{
	aef = 0; fc = 750; e = { 0,1 };
	tl = trunk_length; ft = "peanuts";
}
giraffes::giraffes(double neck_length)
{
	aef = 0; fc = 500; e = { 0,1 };
	nl = neck_length; ft = "carrots";
}
monkeys::monkeys(double arm_length)
{
	aef = 0; fc = 300; e = { 0,1 };
	al = arm_length; ft = "bananas";
}

seller::seller()
{
	em = 0; f[0] = { "peanuts",40000 }; f[1] = { "carrots",7000 }; f[2] = { "bananas",4000 };
}
zoo_keeper::zoo_keeper()
{
	cd = 0;
}
adult_v::adult_v(int id, int children_number, double money, int temp0) { ID = id; cn = children_number; m = money; temp = temp0; }
void adult_v::buy()
{
	m -= (1 + cn*0.4);//tickets
	c[0].cf[0] = temp / 20; c[0].cf[1] = temp / 30; c[0].cf[2] = temp / 50;
}

void Zoo::display()
{
	cout << "Simulation Result: " << endl
		<< "The number of days the zoo was opened for: " << td << endl;
	if (s == 2) { cout << "The zoo closed because the zoo keeper had enough of cleaning and quit!" << endl; }
	else if (s == 3) { cout << "The zoo closed because the seller ran out of peanuts." << endl; }
	else if (s == 4) { cout << "The zoo closed because the seller ran out of carrots." << endl; }
	else if (s == 5) { cout << "The zoo closed because the seller ran out of bananas." << endl; }
	cout << "The total number of adult visitors: " << ta << endl
		<< "The total number of children visitors: " << tc << endl
		<< "The total amount of money made by the seller: " << sl.em << "dollars" << endl
		<< "The number of days the zoo keeper spent cleaning: " << zk.cd << endl
		<< "The number of days elepphants enclosure was closed for: " << el.e.cd << endl
		<< "The number of days giraffes enclosure was closed for: " << gr.e.cd << endl
		<< "The number of days monkeys enclosure was closed for: " << mk.e.cd << endl;
}
void Zoo::simulation()
{
	srand(time(0));
	while (s == 1) { run_a_day(); }
	display();
}
void Zoo::check()
{
	if (zk.cd > 9) { s = 2; }
	else if (sl.f[0].a < 1) { s = 3; }
	else if (sl.f[1].a < 1) { s = 4; }
	else if (sl.f[2].a < 1) { s = 5; }
}
void Zoo::run_a_day()
{
	check(); if (s != 1);
	else
	{
		td++; if (mk.e.dl > 2000) { mk.e.s = 0; mk.e.dl = 0; zk.cd++; el.e.cd++; }
		else if (gr.e.dl > 2000) { gr.e.s = 0; gr.e.dl = 0; zk.cd++; el.e.cd++; }
		else if (el.e.dl > 2000) { el.e.s = 0; el.e.dl = 0; zk.cd++; el.e.cd++; }
		int adultsnum = rand() % 21 + 20;
		adult_v *adults = new adult_v[adultsnum];
		ta += adultsnum;
		for (int j = 0; j < adultsnum; j++)
		{
			adults[j].m = (double)(rand() % 11 + 10);
			adults[j].temp = ((adults[j].m) * 100) / 3;
			adults[j].cn = rand() % 3 + 1;
			tc += adults[j].cn;
			adults[j].c = new child_v[adults[j].cn];
			double tempmoney = adults[j].m;
			adults[j].buy();
			sl.em += tempmoney;
			sl.f[0].a -= (int)adults[j].temp / 20; sl.f[1].a -= (int)adults[j].temp / 30; sl.f[2].a -= (int)adults[j].temp / 50;
			if (el.e.s == 1) { el.eat_n_shit(adults[j].c[0].cf[0]); }
			if (gr.e.s == 1) { gr.eat_n_shit(adults[j].c[0].cf[1]); }
			if (mk.e.s == 1) { mk.eat_n_shit(adults[j].c[0].cf[2]); }
			//delete adults[j].c;
			//adults[j].c = NULL;
		}
		//delete adults;
		//adults = NULL;
	}
}