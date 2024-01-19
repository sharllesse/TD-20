#include "pch.h"
#include "Vector.h"

//Vector2

template Vector2<double>::Vector2();
template Vector2<float>::Vector2();
template Vector2<int>::Vector2();
template Vector2<unsigned>::Vector2();
template Vector2<short>::Vector2();

template Vector2<double>::Vector2(double, double);
template Vector2<float>::Vector2(float, float);
template Vector2<int>::Vector2(int, int);
template Vector2<unsigned>::Vector2(unsigned, unsigned);
template Vector2<short>::Vector2(short, short);

template Vector2<double>::~Vector2();
template Vector2<float>::~Vector2();
template Vector2<int>::~Vector2();
template Vector2<unsigned>::~Vector2();
template Vector2<short>::~Vector2();

//Vector3

template Vector3<double>::Vector3();
template Vector3<float>::Vector3();
template Vector3<int>::Vector3();
template Vector3<unsigned>::Vector3();
template Vector3<short>::Vector3();

template Vector3<double>::Vector3(double, double, double);
template Vector3<float>::Vector3(float, float, float);
template Vector3<int>::Vector3(int, int, int);
template Vector3<unsigned>::Vector3(unsigned, unsigned, unsigned);
template Vector3<short>::Vector3(short, short, short);

template Vector3<double>::~Vector3();
template Vector3<float>::~Vector3();
template Vector3<int>::~Vector3();
template Vector3<unsigned>::~Vector3();
template Vector3<short>::~Vector3();