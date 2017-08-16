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
		fatalError("���ؽ����̴�<vertex shader> ����µ��� �����߽��ϴ�!");
	}


	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID==0)
	{
		fatalError("�����׸�Ʈ ���̴�<fragment shader> ����µ��� �����߽��ϴ�!");
	}



}

void GLSLProgram::linkShaders()
{

}