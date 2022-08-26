#pragma once
#include<Windows.h>
#include<vector>
#include"vertex.h"
#include"Martix.h"
#include"camera.h"
#include"vector.h"
#include"color.h"
//device类，包含MVP矩阵，齐次剪切、视口变换

class device {
public:
	HDC hdc;
    int width, height;
    const float PI = 3.1415926;
public:
    device(){}
    device(HDC hdc, int w, int h);
    //按顺序依次为顶点经过的矩阵处理，Model、camera（view）、projection 在MVP矩阵变换之后，进行齐次剪切和视口变换
    Matrix TransM(vec3f v);//平移
    Matrix ScaleM(vec3f v);//拉伸
    Matrix RotationX(float angle);//X轴旋转
    Matrix RotationY(float angle);//Y
    Matrix RotationZ(float angle);//z
    Matrix RotationM(vec3f v);//旋转矩阵
    Matrix Model(vec3f t, vec3f r, vec3f s);//模型变换矩阵
    Matrix M_view(camera v);//摄像机变换矩阵
    Matrix M_view();//默认摄像机在世界坐标位置看向-z
    Matrix M_ortho(float fo, float aspect, float n, float f);//正交投影矩阵
    Matrix M_ortho();//默认视椎体的fov为90度，宽高比与设备相同，近平面为-5，远平面为-50
    Matrix M_persp(float fo, float aspect, float n, float f);//透视投影矩阵
    Matrix M_persp();//默认视椎体的fov为90度，宽高比与设备相同，近平面为-5，远平面为-50
    Matrix MVP();//model、camera、proection矩阵依次右乘
    void PrepareRasterization(vertex& vertex);//齐次剪切和视口变换

    void DDALine(HDC hDC, vertex v1, vertex v2);
    void drawTriggle(HDC hdc, vertex v1, vertex v2, vertex v3,color color);
    int maxn(int x1, int x2, int x3)const;
    int minn(int x1, int x2, int x3)const;


};

