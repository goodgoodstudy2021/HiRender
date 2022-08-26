#include<iostream>
#include"vector.h"
#include"Martix.h"
#include"color.h"

using namespace std;
int main()
{
	vec3f v1(1,1,1);
	vec3f v2(1,0,0);
	vec3f v3 = v1 - v2;
	v3.print();
	//vector3<float> v3 = v1.normalize();
	//cout << v3.x << endl;
	//cout << v3.y << endl;
	//cout << v3.z << endl;
	//cout << v3.w << endl;
	//cout << tan(45*3.1415/180) << endl;
	//Matrix m;
	//m.print();
	//color c1(1, 2, 3, 0);
	//color c2(1, 2, 3, 0);
	//cout << (c1 + c2).r << endl;
}
