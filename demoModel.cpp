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
//GLuint hProg;
//
//void ProcessKey(GLFWwindow* window, int key, int scanCode, int action, int mode);
//void ProcessMouse(GLFWwindow* window, double xpos, double ypos);
//void ProcessScroll(GLFWwindow* window, double xOffset, double yOffest);
//void DoMovement();
//void Draw(Model& myModel, const ShaderManager& shader);
//
//void Draw(Model& myModel, const ShaderManager& shader)
//{
//	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
//	//glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glUseProgram(hProg);
//
//	glm::mat4 proj = camera.GetProjMatrix();
//	glm::mat4 view = camera.GetViewMatrix();
//	glUniformMatrix4fv(glGetUniformLocation(hProg, "projection"), 1, GL_FALSE, glm::value_ptr(proj));
//	glUniformMatrix4fv(glGetUniformLocation(hProg, "view"), 1, GL_FALSE, glm::value_ptr(view));
//
//	glm::mat4 model;
//	model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
//	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
//	glUniformMatrix4fv(glGetUniformLocation(hProg, "model"), 1, GL_FALSE, glm::value_ptr(model));
//
//	myModel.Draw(shader);
//}
//
//
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
//	GLfloat cameraSpeed = 0.005f;
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
//	ShaderManager shader("shader//model_loadingV.glsl", "shader//model_loadingF.glsl");
//	hProg = shader.GetProgam();
//	Model myModel = Model("model//nanosuit//nanosuit.obj");
//
//
//	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//	camera.SetExtrinsciParams(cameraPos, cameraFront, cameraUp);
//	camera.SetPerspective(fov, static_cast<float>(width) / height, 0.1f, 1000.0f);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		DoMovement();
//		Draw(myModel, shader);
//
//		glfwSwapBuffers(window);
//	}
//	glfwTerminate();
//	return 0;
//}