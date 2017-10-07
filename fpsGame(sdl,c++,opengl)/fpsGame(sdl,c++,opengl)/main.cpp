#include<iostream>
#include"vector3d.h"
using namespace std;

int main()
{
	vector3d vec1;
	vector3d vec2(1, 2, 3);
	vector3d vec3(6, 5, 4);
	cout << vec1 << vec2;
	cout << vec2.length() << endl;
	vec2.normalize();
	cout << vec2;
	vector3d vec4 = vec2 + vec3;
	cout << vec4;
	vec4 += vec2;
	cout << vec4;
		return 0;
}