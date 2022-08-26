#pragma once
#include"vector.h"
class camera
{
public:
	vec3f origin,lookat,up;
	//float n, f, fov;
public:
	camera() :origin(0, 0, 0), lookat(0, 0, -1), up(0, 1, 0){}
	camera(vec3f ori,vec3f look,vec3f up):origin(ori),lookat(look),up(up){}

};