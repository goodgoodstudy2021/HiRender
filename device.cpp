#include"device.h"


device::device(HDC hdc, int w, int h) :hdc(hdc), width(w), height(h) {}
Matrix device::M_view(camera v)
{
    //M_view=R_view*T_view
    vec3f lookdir = v.lookat - v.origin;
    lookdir.normalize();
    lookdir * -1;
    vec3f rightdir = v.lookat ^ v.up;
    rightdir.normalize();
    vec3f updir = rightdir ^ lookdir;
    updir.normalize();

    //位移矩阵，将相机平移到世界坐标中心
    Matrix T_view;
    T_view.value[0][3] = -v.origin.x;
    T_view.value[1][3] = -v.origin.y;
    T_view.value[2][3] = -v.origin.z;

    //旋转矩阵，将相机与世界坐标旋转重合
    Matrix R_view;
    R_view.value[0][0] = rightdir.x;
    R_view.value[0][1] = rightdir.y;
    R_view.value[0][2] = rightdir.z;
    R_view.value[1][0] = updir.x;
    R_view.value[1][1] = updir.y;
    R_view.value[1][2] = updir.z;
    R_view.value[2][0] = lookdir.x;
    R_view.value[2][1] = lookdir.y;
    R_view.value[2][2] = lookdir.z;

    return R_view * T_view;
}
Matrix device::M_view()
{
    camera v;
    //M_view=R_view*T_view
    vec3f lookdir = v.lookat - v.origin;
    lookdir.normalize();
    lookdir * -1;
    vec3f rightdir = v.lookat ^ v.up;
    rightdir.normalize();
    vec3f updir = rightdir ^ lookdir;
    updir.normalize();

    //位移矩阵，将相机平移到世界坐标中心
    Matrix T_view;
    T_view.value[0][3] = -v.origin.x;
    T_view.value[1][3] = -v.origin.y;
    T_view.value[2][3] = -v.origin.z;

    //旋转矩阵，将相机与世界坐标旋转重合
    Matrix R_view;
    R_view.value[0][0] = rightdir.x;
    R_view.value[0][1] = rightdir.y;
    R_view.value[0][2] = rightdir.z;
    R_view.value[1][0] = updir.x;
    R_view.value[1][1] = updir.y;
    R_view.value[1][2] = updir.z;
    R_view.value[2][0] = lookdir.x;
    R_view.value[2][1] = lookdir.y;
    R_view.value[2][2] = lookdir.z;

    return R_view * T_view;
}
Matrix device::M_ortho()
{
    float fov = tan(90 / 2 * 3.1415926 / 180);//弧度数/pi=角度值/180
    float aspect = width / height;
    float n = -5, f = -50;

    //https://zhuanlan.zhihu.com/p/122411512
    Matrix m;
    m.value[0][0] = 1 / fov * aspect * n;
    m.value[1][1] = 1 / fov * n;
    m.value[2][2] = 2 / (n - f);
    m.value[2][3] = -(n + f) / (n - f);
    return m;
}
Matrix device::M_ortho(float fo, float aspect, float n, float f)
{
    float fov = tan(fo / 2 * 3.1415926 / 180);//弧度数/pi=角度值/180
    //float aspect = width / height;
    //float n = -5, f = -50;

    //https://zhuanlan.zhihu.com/p/122411512
    Matrix m;
    m.value[0][0] = 1 / fov * aspect * n;
    m.value[1][1] = 1 / fov * n;
    m.value[2][2] = 2 / (n - f);
    m.value[2][3] = -(n + f) / (n - f);
    return m;
}
Matrix device::M_persp()
{
    //M_persp=M_ortho*M_persp->ortho;
    float fov = tan(90 / 2 * 3.1415926 / 180);//弧度数/pi=角度值/180
    float aspect = width / height;
    float n = -5, f = -50;

    //Matrix m1 = M_ortho();
    //Matrix M_persp_To_ortho;
    //M_persp_To_ortho.value[0][0] = n;
    //M_persp_To_ortho.value[1][1] = n;
    //M_persp_To_ortho.value[2][2] = n+f;
    //M_persp_To_ortho.value[2][3] = -n*f;
    //M_persp_To_ortho.value[3][2] = 1;
    //M_persp_To_ortho.value[3][3] = 0;

    Matrix persp;
    persp.value[0][0] = 1 / aspect * fov;
    persp.value[1][1] = fov;
    persp.value[2][2] = (n + f) / (n - f);
    persp.value[2][3] = -(2 * n * f) / (n - f);
    persp.value[3][2] = 1;
    persp.value[3][3] = 0;
    return persp;
}
Matrix device::M_persp(float fo, float aspect, float n, float f)
{
    //M_persp=M_ortho*M_persp->ortho;
    float fov = tan(fo / 2 * 3.1415926 / 180);//弧度数/pi=角度值/180
    //float aspect = width / height;
    //float n = -5, f = -50;

    Matrix m1 = M_ortho();
    Matrix M_persp_To_ortho;
    M_persp_To_ortho.value[0][0] = n;
    M_persp_To_ortho.value[1][1] = n;
    M_persp_To_ortho.value[2][2] = n + f;
    M_persp_To_ortho.value[2][3] = -n * f;
    M_persp_To_ortho.value[3][2] = 1;
    M_persp_To_ortho.value[3][3] = 0;

    return m1 * M_persp_To_ortho;
}
Matrix device::TransM(vec3f v)
{
    Matrix m;
    m.value[0][3] = v.x;
    m.value[1][3] = v.y;
    m.value[2][3] = v.z;
    return m;
}
Matrix device::ScaleM(vec3f v)
{
    Matrix m;
    m.value[0][0] = v.x;
    m.value[1][1] = v.y;
    m.value[2][2] = v.z;

    return m;
}
Matrix device::RotationX(float angle)
{
    float Angle = angle * PI / 180;
    Matrix m;
    m.value[1][1] = cos(Angle);
    m.value[1][2] = -sin(Angle);
    m.value[2][1] = sin(Angle);
    m.value[2][2] = cos(Angle);
    return m;
}
Matrix device::RotationY(float angle)
{
    float Angle = angle * PI / 180;
    Matrix m;
    m.value[0][0] = cos(Angle);
    m.value[0][2] = sin(Angle);
    m.value[2][0] = -sin(Angle);
    m.value[2][2] = cos(Angle);
    return m;
}
Matrix device::RotationZ(float angle)
{
    float Angle = angle * PI / 180;
    Matrix m;
    m.value[0][0] = cos(Angle);
    m.value[0][1] = -sin(Angle);
    m.value[1][0] = sin(Angle);
    m.value[1][1] = cos(Angle);
    return m;
}
Matrix device::RotationM(vec3f v)
{
    Matrix X = RotationX(v.x);
    Matrix Y = RotationY(v.y);
    Matrix Z = RotationZ(v.z);
    return X * Y * Z;
}
Matrix device::Model(vec3f t, vec3f r, vec3f s)
{
    Matrix trans = TransM(t);
    Matrix rotation = RotationM(r);
    Matrix scale = ScaleM(s);
    return trans * rotation * scale;
}
Matrix device::MVP()
{
    vec3f trans(0, 0, 0);//平移
    vec3f rotation(0, 0, 0);//旋转
    vec3f scale(1, 1, 1);//伸缩

    camera v(vec3f(0.1, 0, 0), vec3f(0, 0, -1), vec3f(0, 1, 0));


    Matrix M = Model(trans, rotation, scale);
    //Matrix V = M_view();
    Matrix V = M_view(v);
    Matrix P = M_persp();
    return  M * V * P;
}
void device::DDALine(HDC hDC, vertex v1, vertex v2)
{
    float x0 = v1.pos.x;
    float x1 = v2.pos.x;
    float y0 = v1.pos.y;
    float y1 = v2.pos.y;

    int dx, dy, steps;
    float x, y, xIncre, yIncre;
    dx = x1 - x0;
    dy = y1 - y0;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);   //选择较大者作为行进方向
    xIncre = (float)dx / (float)steps;               //x方向增量
    yIncre = (float)dy / (float)steps;               //y方向增量
    x = x0;
    y = y0;
    for (int i = 0; i < steps; i++)
    {
        SetPixel(hDC, x, y, (255, 0, 0));
        x += xIncre;
        y += yIncre;
    }
}
void device::PrepareRasterization(vertex& vertex)
{
    //透视除法&视口映射
    //齐次坐标转化，除以w
    float reciprocalW = 1.0f / vertex.pos.w;
    vertex.pos.x = vertex.pos.x * reciprocalW;
    vertex.pos.y = vertex.pos.y * reciprocalW;
    vertex.pos.z = vertex.pos.z * reciprocalW;
    vertex.pos.w = 1;

    Matrix m;
    m.value[0][0] = -width / 2;
    m.value[1][1] = height / 2;
    m.value[0][3] = width / 2;
    m.value[1][3] = height / 2;
    vertex.pos = m * vertex.pos;
    vertex.pos.x = static_cast<int>(vertex.pos.x);
    vertex.pos.y = static_cast<int>(vertex.pos.y);
    vertex.pos.z = static_cast<int>(vertex.pos.z);

}
void device::drawTriggle(HDC hdc, vertex v1, vertex v2, vertex v3,color color)
{
    Matrix m = MVP();
    v1.pos = m * v1.pos;
    v2.pos = m * v2.pos;
    v3.pos = m * v3.pos;

    PrepareRasterization(v1);
    PrepareRasterization(v2);
    PrepareRasterization(v3);

    //DDALine(hdc, v1, v2);
    //DDALine(hdc, v2, v3);
    //DDALine(hdc, v3, v1);

    //包围盒
    int box_max_x,box_max_y,box_min_x,box_min_y;

    box_max_x = maxn(v1.pos.x, v2.pos.x, v3.pos.x);
    box_max_y = maxn(v1.pos.y, v2.pos.y, v3.pos.y);
    box_min_x = minn(v1.pos.x, v2.pos.x, v3.pos.x);
    box_min_y = minn(v1.pos.y, v2.pos.y, v3.pos.y);

    //叉乘判断点与三角形的位置关系
    vec2i v12(v2.pos.x - v1.pos.x, v2.pos.y - v1.pos.y);
    vec2i v23(v3.pos.x - v2.pos.x, v3.pos.y - v2.pos.y);
    vec2i v31(v1.pos.x - v3.pos.x, v1.pos.y - v3.pos.y);



    for (int i = box_min_x; i < box_max_x; i++)
    {
        for (int j = box_min_y; j < box_max_y; j++)
        {
            vec2i q(i, j);
            vec2i v1q(i - v1.pos.x, j - v1.pos.y);
            vec2i v2q(i - v2.pos.x, j - v2.pos.y);
            vec2i v3q(i - v3.pos.x, j - v3.pos.y);

            float a = v12 * v1q;
            float b = v23 * v2q;
            float c = v31 * v3q;

            if (!((a<=0||b<=0||c<=0)&&(a>=0||b>=0||c>=0)))
            {
                SetPixel(hdc, i, j, (color.r,color.g,color.b));
            }
            //SetPixel(hdc, i, j, (255,0,0));
        }
    }
}


//三个数排序从小到大
int device::maxn(int x1,int x2,int x3)const 
{
    int temp;
    if (x1 < x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (x1 < x3)
    {
        temp = x1;
        x1 = x3;
        x3 = temp;
    }
    if (x2 < x3)
    {
        temp = x2;
        x2 = x3;
        x3 = temp;
    }
    return x1;
}
int device::minn(int x1, int x2, int x3)const
{
    int temp;
    if (x1 < x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (x1 < x3)
    {
        temp = x1;
        x1 = x3;
        x3 = temp;
    }
    if (x2 < x3)
    {
        temp = x2;
        x2 = x3;
        x3 = temp;
    }
    return x3;
}
