// Matrix.cpp : 定义控制台应用程序的入口点。
//矩阵元素为int类型

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
	output << endl << obj.a << " " << obj.b << endl << obj.c << " " << obj.d << endl << endl;//格式还能对齐一下
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
	cout << "测试使用四个矩阵a,b,c,d" << endl;
	Matrix a, b, c, d;

	cout << "初始化结果：" << a;

	cout << "请以\"左上 右上 左下 右下\"顺序输入四个2*2矩阵a,b,c,d（元素均为int类型）,回车分隔：" << endl;
	cin >> a >> b >> c >> d;

	cout << "测试连续加，减，乘，数乘：" << endl;
	cout << "a+b+c+d=" << a + b + c + d
		<< "a-b-c-d=" << a - b - c - d
		<< "a*b*c=" << a * b * c
		<< "a*2*3=" << a * 2 * 3;

	cout << "测试+=、-=、*=、数*=：" << endl;
	a += b; b -= c; c *= d; d *= 2;
	cout << "a+=b后a=" << a
		<< "b-=c后b=" << b
		<< "c*=d后c=" << c
		<< "d*=2后d=" << d;

	cout << "测试==、!=运算结果" << endl
		<< "测试==，请输入两个2*2矩阵a,b：" << endl;
	cin >> a >> b;
	cout << "a==b的判断结果为" << boolalpha << (a == b) << noboolalpha << endl
		<< "测试!=，请输入两个2*2矩阵a,b：" << endl;
	cin >> a >> b;
	cout << "a!=b的判断结果为" << boolalpha << (a != b) << noboolalpha << endl
		<< "测试结束，谢谢" << endl;
	//system("pause");
	return 0;
}