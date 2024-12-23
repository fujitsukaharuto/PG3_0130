#pragma once
#include <cmath>

class Vector2My
{
public:

	float x;
	float y;

	//Constructor

	Vector2My() = default;
	Vector2My(float x, float y) :x(x), y(y) {}
	Vector2My(const Vector2My& v) :x(v.x), y(v.y) {}

	//Operator

	Vector2My& operator = (const Vector2My& v) {
		x = v.x;
		y = v.y;
		return *this;
	}

	bool operator == (const Vector2My& v) const {
		return (x == v.x && y == v.y);
	}

	bool operator != (const Vector2My& v) const {
		return (x != v.x || y != v.y);
	}

	const Vector2My& operator+() const {
		return *this;
	}

	Vector2My& operator+() {
		return *this;
	}

	Vector2My operator-() const {
		return Vector2My(-x, -y);
	}

	Vector2My& operator += (const Vector2My& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2My operator + (const Vector2My& v) const {
		return Vector2My(x + v.x, y + v.y);
	}

	Vector2My& operator -= (const Vector2My& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2My operator - (const Vector2My& v) const {
		return Vector2My(x - v.x, y - v.y);
	}

	Vector2My& operator *= (float k) {
		x *= k;
		y *= k;
		return *this;
	}

	Vector2My operator * (float k) const {
		return Vector2My(x * k, y * k);
	}

	Vector2My& operator /= (float k) {
		x /= k;
		y /= k;
		return *this;
	}

	Vector2My operator / (float k)const {
		return Vector2My(x / k, y / k);
	}

	float operator * (const Vector2My& v) const {
		return (x * v.x) + (y * v.y);
	}

	//Function

	float Length() const {
		return std::sqrtf((*this) * (*this));
	}

	Vector2My NormaliZe()const {
		const float leng = Length();
		return leng == 0 ? *this : *this / leng;
	}

	float Angle() const {
		return std::atan2f(y, x);
	}
};