#pragma once
#include<GL/glew.h>

class Sprite
{
public:
	Sprite(); 
	~Sprite();

	void init(float x, float y, float width, float height);
	void draw();


private:
	int _x;
	int _y;
	int _width;
	int _height;
	GLuint _vboID;

};

