#pragma once
#include"vertex.h"
#include<vector>
#include"device.h"

class mesh
{
public:
	std::vector<vertex> v;

public:

	mesh triggle(vertex v1,vertex v2,vertex v3)
	{
		v.push_back(v1);
		v.push_back(v2);
		v.push_back(v3);
	}
};