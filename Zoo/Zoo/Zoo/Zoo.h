#pragma once
#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
using namespace std;

//以下变量全名都在注释里，光标移至变量名可看全名
//以下省略set,get函数，功能用fiend class代替

class Money
{
	friend class Zoo;
public:
	Money(int, int);
	Money operator +(const Money)const;
	Money operator +(const double)const;
	Money operator -(const Money)const;
	Money operator -(const double)const;
private:
	int d;//dollars
	int c;//cents
};

class Food
{
	friend class Zoo;
public:
	Food(string, int);
	Food() { ft = "NAN"; a = 0; }
private:
	string ft;//food_type
	int a;//amount
};

class Enclosure
{
	friend class Zoo;
	friend class Animal;
public:
	Enclosure(int, bool);
	Enclosure() { dl = 0; s = 1; cd = 0; }
private:
	int dl;//dirt_level
	int cd;//total_close_days
	bool s;//status
};

class Animal
{
	friend class Zoo;
public:
	Animal(int, int, double);
	Animal() { aef = 0; fc = 0; w = 0; e = { 0,1 }; }
	void eat_n_shit(int);
protected:
	int aef;//amount_of_eaten_food
	int fc;//food_capacity
	double w;//weight
	Enclosure e;//enclosure
};
class elephants :public Animal
{
	friend class Zoo;
public:
	elephants(double);
private:
	double tl;//trunk_length
	string ft;//food_type
};
class giraffes :public Animal
{
	friend class Zoo;
public:
	giraffes(double);
private:
	double nl;//neck_length
	string ft;//food_type
};
class monkeys :public Animal
{
	friend class Zoo;
public:
	monkeys(double);
private:
	double al;//arm_length
	string ft;//food_type
};

class Person
{
	friend class Zoo;
public:
	Person(string Name, int Age) { name = Name; age = Age; }
	Person() { name = "NAN"; age = 1; }
protected:
	string name;
	int age;
};
class seller :public Person
{
	friend class Zoo;
public:
	seller();
private:
	double em;//earned_money
	const double fp[3] = { 0.2,0.3,0.5 };//food_price, default:[0]peanuts,[1]carrots,[2]bananas
	Food f[3];//food_now_have, default:[0]peanuts,[1]carrots,[2]bananas
};
class zoo_keeper :public Person
{
	friend class Zoo;
public:
	zoo_keeper();
private:
	int cd;//cleaning_days(total)
};
class visitor :public Person
{
	friend class Zoo;
public:
	visitor(int id) { ID = id; }
	visitor() { ID = 0; }
protected:
	int ID;
};
class child_v :public visitor
{
	friend class Zoo;
	friend class adult_v;
public:
	child_v() { for (int j = 0; j < 3; j++)cf[j] = 0; }
private:
	int cf[3];//carried_food_amount, default:[0]peanuts,[1]carrots,[2]bananas
};
class adult_v :public visitor
{
	friend class Zoo;
public:
	adult_v(int, int, double, int);
	adult_v() { cn = 1; m = 10; temp = (m * 100) / 3; }
	~adult_v(){};
	void buy();
private:
	int cn;//children_number(1~3)
	child_v *c;//children
	double m;//money_owned(10~20)
	int temp;
};

class Zoo
{
public:
	Zoo() { td = 0; ta = 0; tc = 0; s = 1; } ~Zoo() {};
	void display();
	void simulation();
	void check();
	void run_a_day();
private:
	int td;//total_days;
	int ta;//total_adults_visitors
	int tc;//total_children_visitors
	int s;//status,1=open,2=close(quit),3=close(peanuts sold out),4(carrots),5(bananas)
	seller sl;//seller
	zoo_keeper zk;//zoo_keeper
	elephants el = { (double)(rand() % 10) / (double)3 };//elephants
	giraffes gr = { (double)(rand() % 10) / (double)3 };//giraffes
	monkeys mk = { (double)(rand() % 10) / (double)3 };//monkeys
};

#endif