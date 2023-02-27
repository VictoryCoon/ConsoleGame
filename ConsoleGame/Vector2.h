#pragma once
struct Vector2
{
public:
	Vector2();
	Vector2(const Vector2& rhs);
	Vector2(const Vector2&& rhs);
	Vector2(float x, float y);
public:
	Vector2& operator=(const Vector2& rhs);
	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);

	Vector2& operator*=(float value);
	Vector2& operator/=(float value);

	Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);

	Vector2 operator*(float value);
	Vector2 operator/(float value);

	float Length();
	float Magnitude();
	float sqrMagnitude();
	Vector2 Normalized();

	static void Normalize(Vector2& vec);

public:
	float x = 0.f;
	float y = 0.f;
public:
	static const Vector2 zero;
	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 left;
	static const Vector2 right;
};
