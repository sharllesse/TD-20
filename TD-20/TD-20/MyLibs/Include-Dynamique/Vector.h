#pragma once
#include <math.h>
#include <iostream>

/*
	MIT License

	Copyright (c) 2023 Charles Lesage

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifdef VECTORLIBDYNAMIQUE_EXPORTS
#define VECTORLIBRARY_API __declspec(dllexport)
#else
#define VECTORLIBRARY_API __declspec(dllimport)
#endif


template<class V>
class VECTORLIBRARY_API Vector2
{
public:
	Vector2() : x(static_cast<V>(0.)), y(static_cast<V>(0.)) {}
	Vector2(V _x, V _y) : x(_x), y(_y) {}
	~Vector2() {}

	V x;
	V y;

	template<typename T>
	Vector2<V> operator+(const Vector2<T> v)
	{
		return Vector2<V>(x + static_cast<V>(v.x), y + static_cast<V>(v.y));
	}

	template<typename T>
	Vector2<V> operator-(const Vector2<T> v)
	{
		return Vector2<V>(x - static_cast<V>(v.x), y - static_cast<V>(v.y));
	}

	Vector2<V> operator*(const float f)
	{
		return Vector2<V>(x * f, y * f);
	}

	Vector2<V> operator/(const float f)
	{
		return Vector2<V>(x / f, y / f);
	}

	template<typename T>
	bool operator==(const Vector2<T> v)
	{
		if (v.x == x && v.y == y)
			return true;

		return false;
	}

	template<typename T>
	bool operator!=(const Vector2<T> v)
	{
		if (v.x == x && v.y == y)
			return false;

		return true;
	}

	template<typename T>
	void lerp(Vector2<T> g, float t)
	{
		x = (1 - t) * x + t * g.x;
		y = (1 - t) * y + t * g.y;
	}

	template<typename T>
	inline float dotProduct(Vector2<T> v)
	{
		return x * v.x + y * v.y;
	}

	inline float getNorme()
	{
		return std::sqrt((this->x * this->x) + (this->y * this->y));
	}

	template<typename T>
	inline float getDistance(Vector2<T> v)
	{
		return std::sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
	}

	template<typename T>
	inline float getAngle(Vector2<T> v)
	{
		return acos(dotProduct(v) / (getNorme() * v.getNorme()));
	}

	inline void normalize()
	{
		if (*this != Vector2<V>())
			*this = *this / getNorme();
	}
};

template<class V>
class VECTORLIBRARY_API Vector3
{
public:
	Vector3() : x(static_cast<V>(0.)), y(static_cast<V>(0.)), z(static_cast<V>(0.)) {}
	Vector3(V _x, V _y, V _z) : x(_x), y(_y), z(_z) {}
	~Vector3() {}

	V x;
	V y;
	V z;

	template<typename T>
	Vector3<V> operator+(const Vector3<T> v)
	{
		return Vector3<V>(this->x + static_cast<V>(v.x), this->y + static_cast<V>(v.y), z + static_cast<V>(v.z));
	}

	template<typename T>
	Vector3<V> operator-(const Vector3<T> v)
	{
		return Vector3<V>(this->x - static_cast<V>(v.x), this->y - static_cast<V>(v.y), z - static_cast<V>(v.z));
	}

	Vector3<V> operator*(const float f)
	{
		return Vector3<V>(this->x * f, this->y * f, z * f);
	}

	Vector3<V> operator/(const float f)
	{
		return Vector3<V>(this->x / f, this->y / f, z / f);
	}

	template<typename T>
	bool operator==(const Vector3<T> v)
	{
		if (v.x == x && v.y == y && v.z == z)
			return true;

		return false;
	}

	template<typename T>
	bool operator!=(const Vector3<T> v)
	{
		if (v.x == x && v.y == y && v.z == z)
			return false;

		return true;
	}

	template<typename T>
	void lerp(Vector3<T> g, float t)
	{
		x = (1 - t) * x + t * g.x;
		y = (1 - t) * y + t * g.y;
		z = (1 - t) * z + t * g.z;
	}

	template<typename T>
	inline float dotProduct(Vector3<T> v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline float getNorme()
	{
		return std::sqrt((x * x) + (y * y) + (z * z));
	}

	template<typename T>
	inline float getDistance(Vector3<T> v)
	{
		return std::sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y) + (v.z - z) * (v.z - z));
	}

	template<typename T>
	inline float getSignedAngleBetween(Vector3<T> v)
	{
		return acos(dotProduct(v) / std::sqrt((v.x * v.x + v.y * v.y + v.z * v.z) * (x * x + y * y + z * z)));
	}

	template<typename T>
	inline float getAngle(Vector3<T> v)
	{
		return acos(dotProduct(v) / (getNorme() * v.getNorme()));
	}

	void normalize()
	{
		if (*this != Vector3<V>())
			*this = *this / getNorme();
	}
};