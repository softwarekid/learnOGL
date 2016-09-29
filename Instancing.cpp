//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "ShaderManager.h"
//#include "Camera.h"
//#include "Model.h"
//
//using namespace std;
//
//int width, height;
//bool keys[1024];
//Camera camera;
//float fov = 45.0f;
//GLuint hProgPlanet;
//GLuint hProgRock;
//
//void ProcessKey(GLFWwindow* window, int key, int scanCode, int action, int mode);
//void ProcessMouse(GLFWwindow* window, double xpos, double ypos);
//void ProcessScroll(GLFWwindow* window, double xOffset, double yOffest);
//void DoMovement();
//void Draw(Model& myModel, const ShaderManager& shader);
//void DrawAsteroid(Model& myModel, const ShaderManager& shader, const int amount);
//
//void Draw(Model& myModel, const ShaderManager& shader)
//{
//	glUseProgram(hProgPlanet);
//
//	glm::mat4 proj = camera.GetProjMatrix();
//	glm::mat4 view = camera.GetViewMatrix();
//	glUniformMatrix4fv(glGetUniformLocation(hProgPlanet, "projection"), 1, GL_FALSE, glm::value_ptr(proj));
//	glUniformMatrix4fv(glGetUniformLocation(hProgPlanet, "view"), 1, GL_FALSE, glm::value_ptr(view));
//
//	glm::mat4 model;
//	model = glm::translate(model, glm::vec3(0.0f, -5.0f, 0.0f));
//	model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
//	glUniformMatrix4fv(glGetUniformLocation(hProgPlanet, "model"), 1, GL_FALSE, glm::value_ptr(model));
//
//	myModel.Draw(shader);
//}
//
//
//void DrawAsteroid(Model& myModel, const ShaderManager& shader, const int amount)
//{
//	glUseProgram(hProgRock);
//	glm::mat4 proj = camera.GetProjMatrix();
//	glm::mat4 view = camera.GetViewMatrix();
//	glUniformMatrix4fv(glGetUniformLocation(hProgPlanet, "projection"), 1, GL_FALSE, glm::value_ptr(proj));
//	glUniformMatrix4fv(glGetUniformLocation(hProgPlanet, "view"), 1, GL_FALSE, glm::value_ptr(view));
//	// Generate a large list of semi-random model transformation matrices
//
//	glBindTexture(GL_TEXTURE_2D, myModel.loadedTextues[0].id); // Note we also made the textures_loaded vector public (instead of private) from the model class.
//	for (GLuint i = 0; i < myModel.meshes.size(); i++)
//	{
//		glBindVertexArray(myModel.meshes[i].VAO);
//		glDrawElementsInstanced(GL_TRIANGLES, myModel.meshes[i].vertices.size(), GL_UNSIGNED_INT, 0, amount);
//		glBindVertexArray(0);
//	}
//}
//void ProcessKey(GLFWwindow* window, int key, int scanCode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	}
//	if (action == GLFW_PRESS)
//	{
//		keys[key] = true;
//	}
//	else if (action == GLFW_RELEASE)
//	{
//		keys[key] = false;
//	}
//}
//
//void ProcessMouse(GLFWwindow* window, double xpos, double ypos)
//{
//	camera.SetFrontBasedOnScreenCoords(xpos, ypos);
//}
//
//void ProcessScroll(GLFWwindow* window, double xOffset, double yOffest)
//{
//	yOffest *= 0.1;
//	if (fov >= 1.0f && fov <= 45.0f)
//		fov -= yOffest;
//	if (fov <= 1.0f)
//		fov = 1.0f;
//	if (fov >= 45.0f)
//		fov = 45.0f;
//	camera.fov = fov;
//}
//
//void DoMovement()
//{
//	GLfloat cameraSpeed = 0.5f;
//	if (keys[GLFW_KEY_W])
//		camera.MoveForward(cameraSpeed);
//	if (keys[GLFW_KEY_S])
//		camera.MoveForward(-cameraSpeed);
//	if (keys[GLFW_KEY_A])
//		camera.MoveRight(-cameraSpeed);
//	if (keys[GLFW_KEY_D])
//		camera.MoveRight(cameraSpeed);
//}
//
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//	GLFWwindow* window = glfwCreateWindow(800, 600, "learnopengl", nullptr, nullptr);
//	if (window == nullptr)
//	{
//		cout << "fail to create window" << endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	glfwSetKeyCallback(window, ProcessKey);
//	glfwSetCursorPosCallback(window, ProcessMouse);
//	glfwSetScrollCallback(window, ProcessScroll);
//
//	glewExperimental = true;
//	GLenum err = glewInit();
//	if (GLEW_OK != err)
//	{
//		cout << "glew init falied \n";
//	}
//
//	ShaderManager shaderPlanet("shader//model_loadingV.glsl", "shader//model_loadingF.glsl");
//	hProgPlanet = shaderPlanet.GetProgam();
//
//	ShaderManager shaderRockInstance("shader//instanceV.glsl", "shader//instanceF.glsl");
//	hProgRock = shaderRockInstance.GetProgam();
//
//	Model modelPlanet = Model("model//planet//planet.obj");
//	Model modelRock = Model("model//rock//rock.obj");
//
//	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 155.0f);
//	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//	camera.SetExtrinsciParams(cameraPos, cameraFront, cameraUp);
//	camera.SetPerspective(fov, static_cast<float>(width) / height, 0.1f, 1000.0f);
//
//	GLuint amount = 100000;
//	glm::mat4* modelMatrices;
//	modelMatrices = new glm::mat4[amount];
//	srand(glfwGetTime()); // initialize random seed	
//	GLfloat radius = 150.0f;
//	GLfloat offset = 25.0f;
//	for (GLuint i = 0; i < amount; i++)
//	{
//		glm::mat4 model;
//		// 1. Translation: Randomly displace along circle with radius 'radius' in range [-offset, offset]
//		GLfloat angle = (GLfloat)i / (GLfloat)amount * 360.0f;
//		GLfloat displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat x = sin(angle) * radius + displacement;
//		displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat y = -2.5f + displacement * 0.4f; // Keep height of asteroid field smaller compared to width of x and z
//		displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat z = cos(angle) * radius + displacement;
//		model = glm::translate(model, glm::vec3(x, y, z));
//
//		// 2. Scale: Scale between 0.05 and 0.25f
//		GLfloat scale = (rand() % 20) / 100.0f + 0.05;
//		model = glm::scale(model, glm::vec3(scale));
//
//		// 3. Rotation: add random rotation around a (semi)randomly picked rotation axis vector
//		GLfloat rotAngle = (rand() % 360);
//		model = glm::rotate(model, rotAngle, glm::vec3(0.4f, 0.6f, 0.8f));
//
//		// 4. Now add to list of matrices
//		modelMatrices[i] = model;
//	}
//
//
//	// Set transformation matrices as an instance vertex attribute (with divisor 1)
//	// NOTE: We're cheating a little by taking the, now publicly declared, VAO of the model's mesh(es) and adding new vertexAttribPointers
//	// Normally you'd want to do this in a more organized fashion, but for learning purposes this will do.
//	for (GLuint i = 0; i < modelRock.meshes.size(); i++)
//	{
//		GLuint VAO = modelRock.meshes[i].VAO;
//		GLuint buffer;
//		glBindVertexArray(VAO);
//		glGenBuffers(1, &buffer);
//		glBindBuffer(GL_ARRAY_BUFFER, buffer);
//		glBufferData(GL_ARRAY_BUFFER, amount * sizeof(glm::mat4), &modelMatrices[0], GL_STATIC_DRAW);
//		// Set attribute pointers for matrix (4 times vec4)
//		glEnableVertexAttribArray(3);
//		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid*)0);
//		glEnableVertexAttribArray(4);
//		glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid*)(sizeof(glm::vec4)));
//		glEnableVertexAttribArray(5);
//		glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid*)(2 * sizeof(glm::vec4)));
//		glEnableVertexAttribArray(6);
//		glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid*)(3 * sizeof(glm::vec4)));
//
//		glVertexAttribDivisor(3, 1);
//		glVertexAttribDivisor(4, 1);
//		glVertexAttribDivisor(5, 1);
//		glVertexAttribDivisor(6, 1);
//
//		glBindVertexArray(0);
//	}
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		DoMovement();
//		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
//		//glClearDepth(1.0f);
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		Draw(modelPlanet, shaderPlanet);
//		DrawAsteroid(modelRock, shaderRockInstance, amount);
//
//		glfwSwapBuffers(window);
//	}
//	glfwTerminate();
//	delete[] modelMatrices;
//	return 0;
//}