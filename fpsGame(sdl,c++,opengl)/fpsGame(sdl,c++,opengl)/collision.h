#pragma once
#ifndef COLLISION_H
#define COLLISION_H 
#include"objloader.h"

class collision
{

public:
	static bool Raysphere(float xc, float yc, float zc,
		float xd, float yd, float zd,
		float xs, float ys, float zs,
		float r, float* dist = NULL, coordinate *point = NULL);

	static bool Rayplane(float nx, float ny, float nz,

		)
		static float TriangleArea();
		static bool SphereSphere();
	static float PointDistance();
	static bool SpherePlane();

	collision();

	~collision();
};

#endif // !COLLISION_H