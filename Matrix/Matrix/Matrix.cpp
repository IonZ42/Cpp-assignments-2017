// Matrix.cpp : �������̨Ӧ�ó������ڵ㡣
//����Ԫ��Ϊint����

#include "stdafx.h"
#include "Matrix.h"
#include<iostream>
#include<iomanip>
using namespace std;

istream& operator >>(istream& input, Matrix & obj)
{
	input >> obj.a;
	input.ignore();
	input >> obj.b;
	input.ignore();
	input >> obj.c;
	input.ignore();
	input >> obj.d;
	return input;
}

ostream& operator <<(ostream& output, Matrix & obj)
{
	output << endl << obj.a << " " << obj.b << endl << obj.c << " " << obj.d << endl << endl;//��ʽ���ܶ���һ��
	return output;
}

Matrix::Matrix()
{
	a = 1;
	b = 0;
	c = 0;
	d = 1;
}

Matrix::Matrix(const Matrix& origin)
{
	a = origin.a;
	b = origin.b;
	c = origin.c;
	d = origin.d;
}

Matrix::~Matrix()
{}

bool Matrix::operator ==(const Matrix & right)
{
	if (a == right.a) {
		if (b == right.b) {
			if (c == right.c) {
				if (d == right.d)
					return 1;
			}
		}
	}
	return 0;
}

Matrix Matrix:: operator +(const Matrix &right)const
{
	Matrix temp = *this;
	temp.a += right.a;
	temp.b += right.b;
	temp.c += right.c;
	temp.d += right.d;
	return temp;
}

Matrix Matrix:: operator -(const Matrix &right)const
{
	Matrix temp = *this;
	temp.a -= right.a;
	temp.b -= right.b;
	temp.c -= right.c;
	temp.d -= right.d;
	return temp;
}

Matrix Matrix:: operator *(const Matrix &right)const
{
	Matrix temp = *this;
	temp.a = temp.a*right.a + temp.b*right.c;
	temp.b = temp.a*right.b + temp.b*right.d;
	temp.c = temp.c*right.a + temp.d*right.c;
	temp.d = temp.c*right.b + temp.d*right.d;
	return temp;
}

Matrix Matrix:: operator *(int n)const
{
	Matrix temp = *this;
	temp.a *= n;
	temp.b *= n;
	temp.c *= n;
	temp.d *= n;
	return temp;
}

const Matrix& Matrix:: operator +=(const Matrix &right)
{
	*this = *this + right;
	return *this;
}

const Matrix& Matrix:: operator -=(const Matrix &right)
{
	*this = *this - right;
	return *this;
}

const Matrix& Matrix:: operator *=(const Matrix &right)
{
	*this = *this * right;
	return *this;
}

const Matrix& Matrix:: operator *=(int right)
{
	*this = *this * right;
	return *this;
}

int main()
{
	cout << "����ʹ���ĸ�����a,b,c,d" << endl;
	Matrix a, b, c, d;

	cout << "��ʼ�������" << a;

	cout << "����\"���� ���� ���� ����\"˳�������ĸ�2*2����a,b,c,d��Ԫ�ؾ�Ϊint���ͣ�,�س��ָ���" << endl;
	cin >> a >> b >> c >> d;

	cout << "���������ӣ������ˣ����ˣ�" << endl;
	cout << "a+b+c+d=" << a + b + c + d
		<< "a-b-c-d=" << a - b - c - d
		<< "a*b*c=" << a * b * c
		<< "a*2*3=" << a * 2 * 3;

	cout << "����+=��-=��*=����*=��" << endl;
	a += b; b -= c; c *= d; d *= 2;
	cout << "a+=b��a=" << a
		<< "b-=c��b=" << b
		<< "c*=d��c=" << c
		<< "d*=2��d=" << d;

	cout << "����==��!=������" << endl
		<< "����==������������2*2����a,b��" << endl;
	cin >> a >> b;
	cout << "a==b���жϽ��Ϊ" << boolalpha << (a == b) << noboolalpha << endl
		<< "����!=������������2*2����a,b��" << endl;
	cin >> a >> b;
	cout << "a!=b���жϽ��Ϊ" << boolalpha << (a != b) << noboolalpha << endl
		<< "���Խ�����лл" << endl;
	//system("pause");
	return 0;
}