#pragma once
#ifndef COLLISION_H
#define COLLISION_H 
#include"objloader.h"

class collision
{

public:
	bool raysphere(float xc, float yc, float zc,
		float xd, float yd, float zd,
		float xs, float ys, float zs,
		float r, float* dist = NULL, coordinate *point = NULL);

	bool rayplane(float nx,float ny,float nz,
				  
		
	)

	collision();

	~collision();
};

#endif // !COLLISION_H