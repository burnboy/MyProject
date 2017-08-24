#include "GLSLProgram.h"
#include"Error.h"

#include<vector>

#include<fstream>

GLSLProgram::GLSLProgram():_numAttributes(0), _programID(0),_vertexShaderID(0),_fragmentShaderID(0)
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
	//vertex and fragment shaders are successfully compiled
	//now time to link them together into a program
	//get a program object
	_programID = glCreateProgram();

	//attach our shaders to our program
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	//link our program
	glLinkProgram(_programID);

	//note different functions here:glgetprogram* instead of glgetshader
	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int*)&isLinked);
	if (isLinked==GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		//maxlength에 널 캐릭터가 포함
		std::vector<char>errorLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);

		//더이상 프로그램이 필요없음
		glDeleteProgram(_programID);
		
		//셰이더 누수를 막음
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);


		std::printf("%s\n", &(errorLog[0]));
		fatalError("shader failed to link");

	}

	//always detach shaders after a successful link
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

void GLSLProgram::addAttribute(const std::string& attributeName)
{
	glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());

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
