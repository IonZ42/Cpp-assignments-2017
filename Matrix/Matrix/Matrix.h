#ifndef MARTIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
	friend istream& operator >>(istream& input, Matrix & obj);
	friend ostream& operator <<(ostream& output, Matrix & obj);
public:
	Matrix();
	Matrix(const Matrix&);
	~Matrix();
	bool operator ==(const Matrix &);
	bool operator !=(const Matrix & right)
	{
		return!(*this == right);
	}
	Matrix operator +(const Matrix &)const;
	Matrix operator -(const Matrix &)const;
	Matrix operator *(const Matrix &)const;
	Matrix operator *(int)const;
	const Matrix& operator +=(const Matrix &);
	const Matrix& operator -=(const Matrix &);
	const Matrix& operator *=(const Matrix &);
	const Matrix& operator *=(int);
private:
	int a, b, c, d;
};

#endif
