using namespace std;
#include<iostream>

class Vector2D
{
public:
        Vector2D(int x, int y);
        Vector2D();
        ~Vector2D();

        int getx()const;
        int gety()const;
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


class Matrix2
{
public:
    Matrix2(int a11, int a21, int a12, int a22);
    Matrix2();
    ~Matrix2();

    int geta11()const;
    int geta12()const;
    int geta21()const;
    int geta22()const;
    void seta11(int a11);
    void seta12(int a12);
    void seta21(int a21);
    void seta22(int a22);

    int det ();
    Matrix2& operator- (const Matrix2& v2);
    Matrix2& operator+ (const Matrix2& m2);
    Matrix2& operator* (const Matrix2& m);
    Vector2D& operator* (const Vector2D& v);
    Matrix2& operator* (int a);
    void operator= ( Matrix2& m2);


protected:
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

int Matrix2::geta11()const
{
    return this->a11;
}

int Matrix2::geta12()const
{
    return this->a12;
}

int Matrix2::geta21()const
{
    return this->a21;
}

int Matrix2::geta22()const
{
    return this->a22;
}

Matrix2& Matrix2::operator+ (const Matrix2& m2)
{
    static Matrix2 m3(this->geta11() + m2.geta11(), this->geta12() + m2.geta12(), this->geta21() + m2.geta21(), this->geta22() + m2.geta22());
    return m3;
}

void Matrix2::operator= ( Matrix2& m2)
{
    this->seta11(m2.geta11());
    this->seta12(m2.geta12());
    this->seta21(m2.geta21());
    this->seta22(m2.geta22());
}

Matrix2& Matrix2::operator- (const Matrix2& m2)
{
    static Matrix2 m3(this->geta11() - m2.geta11(), this->geta21() - m2.geta21(), this->geta12() - m2.geta12(), this->geta22() - m2.geta22());
    return m3;
}

Matrix2& Matrix2::operator* (const Matrix2& m)
{
    int r11 = (this->geta11() * m.geta12() + this->geta12() * m.geta22());
    int r21 = (this->geta21() * m.geta11() + this->geta22() * m.geta21());
    int r12 = (this->geta11() * m.geta12() + this->geta12() * m.geta22());
    int r22 = (this->geta21() * m.geta11() + this->geta22() * m.geta21());
    static Matrix2 res(r11,r21,r12,r22);
    return (res);
}

Matrix2& Matrix2::operator* (int a)
{
    int r11 = a * this->geta11();
    int r21 = a * this->geta21();
    int r12 = a * this->geta12();
    int r22 = a * this->geta22();
    static Matrix2 res(r11,r12,r21,r22);
    return (res);
}

Matrix2& operator* (int a , const Matrix2& m)
{
    int r11 = a * m.geta11();
    int r21 = a * m.geta21();
    int r12 = a * m.geta12();
    int r22 = a * m.geta22();
    static Matrix2 res(r11,r12,r21,r22);
    return (res);
}

Vector2D& Matrix2::operator* (const Vector2D& v)
{
    int r11 = (this->geta11() * v.getx() + this->geta12() * v.gety());
    int r21 = (this->geta21() * v.getx() + this->geta22() * v.gety());
    static Vector2D res(r11, r21);
    return (res);
}

int Matrix2::det ()
{
    return this->a11 * this->a22 - this->a12 * this->a21;
}

std::ostream& operator<<(std::ostream& os, Matrix2& m)
{
    os << m.geta11()<<" "<< m.geta12()<<"\n"<< m.geta21()<<" "<< m.geta22();
    return os;
}

std::istream& operator>>(std::istream &is, Matrix2 &m)
{
    int a11, a12, a21, a22;
    is >> a11 >> a12 >> a21 >> a22;
    m.seta11(a11);
    m.seta12(a12);
    m.seta21(a21);
    m.seta22(a22);
    return is;
}

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

int Vector2D::getx()const
{
        return this->x;
}

Vector2D Vector2D::operator* (const int a)
{
        Vector2D v(this->x * a, this->y * a);
        return v;
}

int Vector2D::gety()const
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

int main()
{
    Matrix2 m1(0, 1, 1, 2);
    Matrix2 m2(0, 1, 2, 2);
    std::cout << "=== Test matrix ===" << std::endl;

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << (m1 + m2) << std::endl;
    std::cout << (m1 - m2) << std::endl;
    std::cout << m1 * 5 << std::endl;
    std::cout << -5 * m2 << std::endl;
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m1 * m2 << std::endl;
    std::cout << m1.det() << std::endl;

    std::cout << "=== Cross test vector and matrix ===" << std::endl;

    Vector2D v1 = {1, 1};
    std::cout << (m1 * v1) << std::endl;
    return 0;
}


