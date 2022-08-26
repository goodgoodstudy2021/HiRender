#pragma once

//color类，对颜色进行处理
class color {

public:
	float r, g, b, a;
	color(float r, float g, float b) :r(r), g(g), b(b){}

	color(float r,float g,float b,float a):r(r),g(g),b(b),a(a){}

	color operator+(const color &c)const 
	{
		return color(r + c.r, g + c.g, b + c.b, a + c.a);
	}
	color operator-(const color& c)const 
	{
		return color(r - c.r, g - c.g, b - c.b, a - c.a);
	}
	color operator*(const color& c)
	{
		return color(r * c.r, g * c.g, b * c.b, a * c.a);
	}
	color operator*(float c)
	{
		return color(r * c, g * c, b * c, a * c);
	}
	color operator/(float c)
	{
		float c1 = 1 / c;
		return color(r * c1, g * c1, b * c1, a * c1);
	}
	color lerp(const color left, const color right, float t)
	{
		return left + (right - left) * t;
	}

};