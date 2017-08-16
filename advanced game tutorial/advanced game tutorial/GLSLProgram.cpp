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
		fatalError("벌텍스셰이더<vertex shader> 만드는데에 실패했습니다!");
	}


	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID==0)
	{
		fatalError("프레그먼트 셰이더<fragment shader> 만드는데에 실패했습니다!");
	}

	std::ifstream vertexFile(vertexShaderFilePath);
	if (vertexFile.fail()) {

		perror(vertexShaderFilePath.c_str());
		fatalError("열기 실패" + vertexShaderFilePath);
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