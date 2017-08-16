#include "GLSLProgram.h"
#include"Error.h"

#include<fstream>

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

	std::ifstream vertexFile(vertexShaderFilePath);
	if (vertexFile.fail()) {

		perror(vertexShaderFilePath.c_str());
		fatalError("���� ����" + vertexShaderFilePath);
	}

	std::string fileContents="";
	std::string line;

	while (std::getline(vertexFile,line))
	{
		fileContents += line + "\n";
	}

	vertexFile.close();

	const char* contentsPtr = fileContents.c_str();

	glShaderSource(_vertexShaderID, 1, &contentsPtr, )



}

void GLSLProgram::linkShaders()
{

}