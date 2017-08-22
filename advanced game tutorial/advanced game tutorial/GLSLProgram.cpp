#include "GLSLProgram.h"
#include"Error.h"

#include<vector>

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

	complieShader(vertexShaderFilePath, _vertexShaderID);
	complieShader(gragmentShaderFilepath, _fragmentShaderID);


}

void GLSLProgram::linkShaders()
{

}

void GLSLProgram::complieShader(const std::string &filePath, GLuint &id)
{
	std::ifstream vertexFile(filePath);
	if (vertexFile.fail()) {

		perror(filePath.c_str());
		fatalError("���� ����" + filePath);
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(vertexFile, line))
	{
		fileContents += line + "\n";
	}

	vertexFile.close();

	const char* contentsPtr = fileContents.c_str();

	glShaderSource(id, 1, &contentsPtr, nullptr);

	glCompileShader(id);

	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		//maxlength �� �� ĳ���͸� �����ϰ� �ִ�
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		//
		//failure�� �Բ� ����
		glDeleteShader(id);//shader�� ���� ���� �ʰ� ���ش�


		std::printf("%s\n", &(errorLog[0]));
		fatalError("shader" + filePath + "failed to complie");
		return;

	}

}
