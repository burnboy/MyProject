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
		fatalError("벌텍스셰이더<vertex shader> 만드는데에 실패했습니다!");
	}


	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID==0)
	{
		fatalError("프레그먼트 셰이더<fragment shader> 만드는데에 실패했습니다!");
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
		fatalError("열기 실패" + filePath);
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

		//maxlength 는 널 캐릭터를 포함하고 있다
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		//
		//failure와 함께 나감
		glDeleteShader(id);//shader가 누수 되지 않게 해준다


		std::printf("%s\n", &(errorLog[0]));
		fatalError("shader" + filePath + "failed to complie");
		return;

	}

}
