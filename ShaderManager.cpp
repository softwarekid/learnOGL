#include "ShaderManager.h"
#include "fstream"
#include <iostream>
#include "Common.h"

using namespace std;

ShaderManager::ShaderManager(const string& vertSrcFile_, const string& fragSrcFile_, const std::string& geomSource_) :vertSrcFile(vertSrcFile_), fragSrcFile(fragSrcFile_), geomSrcFile(geomSource_)
{
	InitShaders();
	InitProgram();
}

GLuint ShaderManager::GetProgam()
{
	return hProg;
}

void ShaderManager::InitShaders()
{
	hVerShader = glCreateShader(GL_VERTEX_SHADER);
	hFragShader = glCreateShader(GL_FRAGMENT_SHADER);
	LoadShaderFile(hVerShader, vertSrcFile);
	LoadShaderFile(hFragShader, fragSrcFile);
	if (geomSrcFile != "")
	{
		hGeomShader = glCreateShader(GL_GEOMETRY_SHADER);
		LoadShaderFile(hGeomShader, geomSrcFile);
	}

}

void ShaderManager::InitProgram()
{
	hProg = glCreateProgram();
	glAttachShader(hProg, hVerShader);
	glAttachShader(hProg, hFragShader);
	if (hGeomShader > 0)
	{
		glAttachShader(hProg, hGeomShader);
	}
	glLinkProgram(hProg);
	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(hProg, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(hProg, 512, NULL, infoLog);
	}
	glUseProgram(hProg);
	glDeleteShader(hVerShader);
	glDeleteShader(hFragShader);
	glDeleteShader(hGeomShader);
}

void ShaderManager::LoadShaderFile(GLuint hShader, string fileName)
{
	ifstream file(fileName.c_str());
	if (file)
	{
		file.seekg(0, file.end);
		int length = file.tellg();
		file.seekg(0, file.beg);
		char* buffer = new char[length + 1];
		memset(buffer, 0, sizeof(char) * (length + 1));
		file.read(buffer, length);
		glShaderSource(hShader, 1, &buffer, NULL);
		delete[] buffer;
		glCompileShader(hShader);
		
		GLint success;
		GLchar infoLog[512];
		glGetShaderiv(hShader, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(hShader, 512, NULL, infoLog);
			cout << fileName << " Compile error: " << infoLog << endl;
		}
	}
	file.close();
}
