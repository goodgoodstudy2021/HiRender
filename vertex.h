#pragma once
#include"vector.h"
#include"color.h"

const color red(255, 0, 0, 0);
class vertex
{
public:
	vec3f pos;
	color color;


	vertex(float x, float y, float z) :pos(x, y, z), color(red) {

		pos.w = 0;
	}

	float lerp(float left, float right, float t)
	{
		return left + (right - left) * t;
	}



};