#pragma once
#include<cmath>
#include<iostream>
template<typename T>
class vector2
{
public:
	T x, y;

public:
	vector2() {}
	vector2(T x, T y) :x(x), y(y){}
	vector2<T> operator+(vector2<T> v)const { return vector2<T>(v.x + this->x, v.y + this->y); }
	vector2<T> operator-(vector2<T> v)const { return  vector2<T>(this->x - v.x, this->y - v.y); }
	vector2<T> operator*(float v)const { return vector2<T>(this->x * v, this->y * v); }
	float operator*(vector2<T> v)const { return (x * v.y - v.x * y); }
};

template<typename T>
class vector3
{
public:
	T x, y, z,w=1;

public:
	vector3() {};
	vector3(T x, T y, T z) :x(x), y(y), z(z) {};
	vector3<T> operator^(vector3<T> v)const {
		return vector3<T>((y * v.z - v.y * z), (v.x * z - v.z * x) ,(x * v.y - v.x * y));
	}//���(�õ�������������������ֱ������)
	vector3<T> operator+(vector3<T> v)const { return vector3<T>(x + v.x, y + v.y, z + v.z); }
	vector3<T> operator-(vector3<T> v)const { return vector3<T>(x - v.x, y - v.y, z - v.z); }
	T operator*(vector3<T> v)const { return (x * v.x+y * v.y+z * v.z); }//��ˣ���ֵ����|a||b|cosA(AΪa��b�ļн�)����ֵ����0�����������н�С��90�ȣ�С��0�нǴ���90�ȣ�
	vector3<T> operator*(float v)const { return vector3<T>(x * v, y * v, z * v); }
	float  norm() { return sqrt(x * x + y * y + z * z); }
	vector3<T> normalize() { return (*this * (1 / norm())); }
	//template<T> friend std::ostream& operator<<(std::ostream& s, vector3<T> v) { s << "(" << "v.x" << " " << "v,y" << " " << "v.z" << ")\n" }
	void print()
	{
		std::cout << "(" << this->x << "," << this->y << "," << this->z << ")"<<std::endl;
	}
};

using vec3i = vector3<int>;
using vec3f = vector3<float>;
using vec2i = vector2<int>;
using vec2f = vector2<float>;