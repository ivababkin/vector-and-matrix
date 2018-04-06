# vector-and-matrix
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Vector2D
{
public:
	Vector2D(int x, int y);
	Vector2D();
	~Vector2D();
	
	int getx();
	int gety();
	void setX(int x);
    void setY(int y);
	
	bool operator== (const Vector2D& v2);
	bool operator!= (const Vector2D& v2);
	
	Vector2D operator- (const Vector2D& v2);
	Vector2D operator+ (const Vector2D& v2);
    Vector2D operator* (const int a);
	int operator* (const Vector2D& v2);
	int x;
	int y;
};
	
Vector2D::Vector2D (int x, int y)
{
	this->x = x;
	this->y = y;
}

void Vector2D::setX(int x)
{
	this->x = x;
}

void Vector2D::setY(int y)
{
	this->y = y;
}

Vector2D::Vector2D () {}	


Vector2D::~Vector2D () {}

int Vector2D::getx()
{
	return this->x;
} 

Vector2D Vector2D::operator* (const int a)
{
	Vector2D v(this->x * a, this->y * a);
	return v;
}

int Vector2D::gety()
{
	return this->y;
} 

bool Vector2D::operator== (const Vector2D& v2)
{
	if ((this->x == v2.x) && (this->y == v2.y))
		return true;
	else 
		return false;
}

Vector2D operator* (int a, const Vector2D& v)
{
	Vector2D v1(v.x * a , v.y * a);
	return v1;
}

bool Vector2D::operator!= (const Vector2D& v2)
{
	if (*this == v2)
		return 0;
	else
		return 1;
}

Vector2D Vector2D::operator+ (const Vector2D& v2)
{
	Vector2D v3(this->x + v2.x ,this->y + v2.y);
	return v3;
}

Vector2D Vector2D::operator- (const Vector2D& v2)
{
	Vector2D v3(this->x - v2.x ,this->y - v2.y);
	return v3;
}

int Vector2D::operator* (const Vector2D& v2)
{
	return (this->x * v2.x + this->y * v2.y);
}



std::ostream& operator<<(std::ostream& os, Vector2D& v)
{
	os <<"("<< v.x <<"; "<< v.y<< ")";
	return os;
}

std::istream& operator>>(std::istream &is, Vector2D &v)
{	
	is >> v.x >> v.y;
	return is;
}

