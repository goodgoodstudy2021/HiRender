#pragma once
#include<iostream>

class Matrix
{
public:
	float value[4][4];

	Matrix()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == j)
				{
					value[i][j] = 1;
				}
				else
					value[i][j] = 0;
			}
		}
	};


	Matrix operator+(const Matrix v) {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->value[i][j] += v.value[i][j];
			}
		}
		return *this;
	}
	Matrix operator-(const Matrix v)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->value[i][j] -= v.value[i][j];
			}
		}
		return *this;
	}
	//срЁк
	Matrix operator * (const Matrix& v) const
	{
		Matrix m;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				m.value[i][j] = 0;//temp
				for (int k = 0; k < 4; k++)
				{
					m.value[i][j] += this->value[i][k] * v.value[k][j];
				}
			}
		}
		return m;
	}
	Matrix operator*(const float v)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->value[i][j] *= v;
			}
		}
		return *this;
	}
	Matrix tranpose()const
	{
		Matrix m;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				m.value[i][j] = this->value[j][i];
			}
		}
		return m;
	}
	vec3f operator*(vec3f v)
	{
		float x = this->value[0][0] * v.x + this->value[0][1] * v.y + this->value[0][2] * v.z + this->value[0][3] * v.w;
		float y = this->value[1][0] * v.x + this->value[1][1] * v.y + this->value[1][2] * v.z + this->value[1][3] * v.w;
		float z = this->value[2][0] * v.x + this->value[2][1] * v.y + this->value[2][2] * v.z + this->value[2][3] * v.w;
		float w = this->value[3][0] * v.x + this->value[3][1] * v.y + this->value[3][2] * v.z + this->value[3][3] * v.w;
		vec3f temp(x, y, z);
		temp.w = w;
		return temp;
	}

	void print() 
	{
		std::cout << this->value[0][0] << " " << this->value[0][1] << " " << this->value[0][2] << " " << this->value[0][3] << "\n"
				  << this->value[1][0] << " " << this->value[1][1] << " " << this->value[1][2] << " " << this->value[1][3] << "\n"
			      << this->value[2][0] << " " << this->value[2][1] << " " << this->value[2][2] << " " << this->value[2][3] << "\n"
			      << this->value[3][0] << " " << this->value[3][1] << " " << this->value[3][2] << " " << this->value[3][3] << std::endl;
	}

};