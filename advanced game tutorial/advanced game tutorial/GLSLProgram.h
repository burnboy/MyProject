#pragma once
#include<string>
#include<GL/glew.h>


class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void compileShaders(const std::string &vertexShaderFilePath,const std::string &gragmentShaderFilepath);

	void linkShaders();

private:

	void complieShader(const std::string &filePath,GLuint &id);

	GLuint _programID;

	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
};

