#include "pch.h"
#include "Vector2.h"

const Vector2 Vector2::zero = Vector2(0.f, 0.f);
const Vector2 Vector2::up = Vector2(0.f, 1.f);
const Vector2 Vector2::down = Vector2(0.f, -1.f);
const Vector2 Vector2::left = Vector2(-1.f, 0.f);
const Vector2 Vector2::right = Vector2(1.f, 0.f);

Vector2::Vector2()
{
    this->x = 0.f;
    this->y = 0.f;
}

Vector2::Vector2(const Vector2& rhs)
{
    x = rhs.x;
    y = rhs.y;
}

Vector2::Vector2(const Vector2&& rhs)
{
    x = rhs.x;
    y = rhs.y;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Vector2& Vector2::operator*=(float value)
{
    this->x *= value;
    this->y *= value;
    return *this;
}

Vector2& Vector2::operator/=(float value)
{
    if (value == 0.f)
    {
        return *this;
    }
    this->x /= value;
    this->y /= value;
    return *this;
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
    Vector2 temp = *this;
    temp += rhs;
    return temp;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
    Vector2 temp = *this;
    temp -= rhs;
    return temp;
}

Vector2 Vector2::operator*(float value)
{
    Vector2 temp = *this;
    temp *= value;
    return temp;
}

Vector2 Vector2::operator/(float value)
{
    Vector2 temp = *this;
    temp /= value;
    return temp;
}

float Vector2::Length()
{
    return sqrtf(x * x + y * y);
}

float Vector2::Magnitude()
{
    return sqrtf(x * x + y * y);
}

float Vector2::sqrMagnitude()
{
    return x * x + y * y;
}


/**/
Vector2 Vector2::Normalized()
{
    Vector2 d = Vector2::zero;
    d.x = this->x;
    d.y = this->y;
    float magnitude = Magnitude();
    d /= magnitude;
    return d;
}

void Vector2::Normalize(Vector2& vec)
{
    float magnitude = vec.Magnitude();
    vec /= magnitude;
}