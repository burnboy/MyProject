#include "GLSLProgram.h"
#include"Error.h"


GLSLProgram::GLSLProgram():_programID(0),_vertexShaderID(0),_fragmentShaderID(0)
{

}


GLSLProgram::~GLSLProgram()
{

}

void GLSLProgram:: compileShaders(const std::string &vertexShaderFilePath, const std::string &gragmentShaderFilepath)
{
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID==0)
	{
		fatalError("벌텍스셰이더<vertex shader> 만드는데에 실패했습니다!");
	}


	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID==0)
	{
		fatalError("프레그먼트 셰이더<fragment shader> 만드는데에 실패했습니다!");
	}



}

void GLSLProgram::linkShaders()
{

}