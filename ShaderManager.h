#ifndef shader_loader_h_
#define shader_loader_h_
#include <gl/glew.h>
#include <string>

class ShaderManager
{
public:
	ShaderManager(const std::string& vertexSource_, const std::string& fragSource_, const std::string& geomSource_= "");
	GLuint GetProgam();
private:
	void InitShaders();
	void InitProgram();
	void LoadShaderFile(GLuint hShader, std::string fileName);
	std::string vertSrcFile;
	std::string fragSrcFile;
	std::string geomSrcFile;

	GLuint hVerShader = 0;
	GLuint hFragShader = 0;
	GLuint hGeomShader = 0;
	GLuint hProg = 0;
};

#endif
