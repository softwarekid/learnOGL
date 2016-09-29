#pragma once
// Std. Includes
#include <vector>
#include <assimp/types.h>
using namespace std;
// GL Includes
#include <GL/glew.h> // Contains all the necessery OpenGL includes
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderManager.h"


struct Vertex {
	// Position
	glm::vec3 Position;
	// Normal
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};

struct Texture {
	GLuint id;
	string type;
	aiString path;
};

class Mesh {
public:
	/*  Mesh Data  */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	/*  Functions  */
	// Constructor
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);

	// Render the mesh
	void Draw(ShaderManager shader);

	/*  Render data  */
	GLuint VAO, VBO, EBO;
private:

	/*  Functions    */
	// Initializes all the buffer objects/arrays
	void setupMesh();
};