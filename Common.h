#pragma once

#include <GL/glew.h>
#include <string>

#define glCheckError() glCheckError_(__FILE__, __LINE__) 

GLint TextureFromFile(const char* path, std::string directory);
GLenum glCheckError_(const char *file, int line);

