#include "vector3d.h"



vector3d::vector3d()//초기화 생성자
{
	x = y = z = 0;
}

vector3d::vector3d(float a, float b) 
{
	x = a, y = b, z = 0;
};
vector3d::vector3d(float a, float b, float c) 
{

};

vector3d::~vector3d()
{


}

float dotProduct(const vector3d& vec2);
vector3d crossProduct(const vector3d& vec2);
float length();
void normalize();


void change(float a, float b, float c);
void change(vector3d& vec2);
void change(vector3d vec2);
void changeX(float a);
void changeY(float a);
void changeZ(float a);