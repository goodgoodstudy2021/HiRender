#pragma once
#include<Windows.h>
#include<vector>
#include"vertex.h"
#include"Martix.h"
#include"camera.h"
#include"vector.h"
#include"color.h"
//device�࣬����MVP������μ��С��ӿڱ任

class device {
public:
	HDC hdc;
    int width, height;
    const float PI = 3.1415926;
public:
    device(){}
    device(HDC hdc, int w, int h);
    //��˳������Ϊ���㾭���ľ�����Model��camera��view����projection ��MVP����任֮�󣬽�����μ��к��ӿڱ任
    Matrix TransM(vec3f v);//ƽ��
    Matrix ScaleM(vec3f v);//����
    Matrix RotationX(float angle);//X����ת
    Matrix RotationY(float angle);//Y
    Matrix RotationZ(float angle);//z
    Matrix RotationM(vec3f v);//��ת����
    Matrix Model(vec3f t, vec3f r, vec3f s);//ģ�ͱ任����
    Matrix M_view(camera v);//������任����
    Matrix M_view();//Ĭ�����������������λ�ÿ���-z
    Matrix M_ortho(float fo, float aspect, float n, float f);//����ͶӰ����
    Matrix M_ortho();//Ĭ����׵���fovΪ90�ȣ���߱����豸��ͬ����ƽ��Ϊ-5��Զƽ��Ϊ-50
    Matrix M_persp(float fo, float aspect, float n, float f);//͸��ͶӰ����
    Matrix M_persp();//Ĭ����׵���fovΪ90�ȣ���߱����豸��ͬ����ƽ��Ϊ-5��Զƽ��Ϊ-50
    Matrix MVP();//model��camera��proection���������ҳ�
    void PrepareRasterization(vertex& vertex);//��μ��к��ӿڱ任

    void DDALine(HDC hDC, vertex v1, vertex v2);
    void drawTriggle(HDC hdc, vertex v1, vertex v2, vertex v3,color color);
    int maxn(int x1, int x2, int x3)const;
    int minn(int x1, int x2, int x3)const;


};

