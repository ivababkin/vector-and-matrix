#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "vector2.cpp"
using namespace std;

class Matrix2
{
public:
	Matrix2(int a11, int a21, int a12, int a22);
	Matrix2();
	~Matrix2();
	
	int geta11();
	int geta12();
	int geta21();
	int geta22();
	void seta11(int a11);
    void seta12(int a12);
	void seta21(int a21);
	void seta22(int a22);
		
	int det ();
	Matrix2 operator- (const Matrix2& v2);
	Matrix2 operator+ (const Matrix2& v2);
    Matrix2 operator* (const Matrix2& m);
    Vector2D operator* (const Vector2D& v);

	int a11, a21;
	int a12, a22;
	
};

Matrix2::Matrix2 (int a11, int a12, int a21, int a22)
{
	this->a11 = a11;
	this->a12 = a12;
	this->a21 = a21;
	this->a22 = a22;
}
Matrix2::Matrix2 () 
{
	this->a11 = 0;
	this->a12 = 0;
	this->a21 = 0;
	this->a22 = 0;
}	
Matrix2::~Matrix2 () {}
void Matrix2::seta11(int x)
{
	this->a11 = x;
}
void Matrix2::seta12(int x)
{
	this->a12 = x;
}
void Matrix2::seta21(int x)
{
	this->a21 = x;
}
void Matrix2::seta22(int x)
{
	this->a22 = x;
}
int Matrix2::geta11()
{
	return this->a11;
}
int Matrix2::geta12()
{
	return this->a12;
}
int Matrix2::geta21()
{
	return this->a21;
}
int Matrix2::geta22()
{
	return this->a22;
}




Matrix2 Matrix2::operator+ (const Matrix2& m2)
{
	Matrix2 m3(this->a11 + m2.a11, this->a12 + m2.a12, this->a21 + m2.a21, this->a22 + m2.a22);
	return m3;
}

Matrix2 Matrix2::operator- (const Matrix2& m2)
{
	Matrix2 m3(this->a11 - m2.a11, this->a21 - m2.a21, this->a12 - m2.a12, this->a22 - m2.a22);
	return m3;
}

Matrix2 Matrix2::operator* (const Matrix2& m)
{
	int r11 = (this->a11 * m.a12 + this->a12 * m.a22);
	int r21 = (this->a21 * m.a11 + this->a22 * m.a21);
	int r12 = (this->a11 * m.a12 + this->a12 * m.a22);
	int r22 = (this->a21 * m.a11 + this->a22 * m.a21);
	Matrix2 res(r11,r21,r12,r22);
	return (res);
}

Vector2D Matrix2::operator* (const Vector2D& v)
{
	int r11 = (this->a11 * v.x + this->a12 * v.y);
	int r21 = (this->a21 * v.x + this->a22 * v.y);
	Vector2D res(r11, r21);
	return (res);
}

int Matrix2::det ()
{
	return this->a11 * this->a22 - this->a12 * this->a21;
}

std::ostream& operator<<(std::ostream& os, Matrix2& m)
{
	os << m.a11<<" "<< m.a12<<"\n"<< m.a21<<" "<< m.a22;
	return os;
}

std::istream& operator>>(std::istream &is, Matrix2 &m)
{	
	is >> m.a11 >> m.a12 >> m.a21 >> m.a22;
	return is;
}

int main()
{
	Matrix2 m1(2, 2, 2, 2);
	Vector2D v1(1, 1);
	Matrix2 m2(1, 1, 1, 1);
	Matrix2 m3(1, 1, 1, 1);
	cout<< m1 <<endl;
	Vector2D v2 = m1 * v1;
	cout<< "v2 "<< v2 <<endl;
	cout<< m3 <<endl;
	return 0;
} 
