//// Std. Includes
//#include <string>
//
//// GLEW
//#define GLEW_STATIC
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// GL includes
//#include "ShaderManager.h"
//#include "Camera.h"
//
//// GLM Mathemtics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//// Other Libs
//#include <SOIL.h>
//#include <iostream>
//
//GLuint hProg;
//float fov = 45.0f;
//// Properties
//GLuint screenWidth = 800, screenHeight = 600;
//
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void Do_Movement();
//GLuint generateMultiSampleTexture(GLuint samples);
//GLuint loadTexture(GLchar* path);
//
//// Camera
//Camera camera;
//bool keys[1024];
//GLfloat lastX = 400, lastY = 300;
//bool firstMouse = true;
//
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//// The MAIN function, from here we start our application and run our Game loop
//int main()
//{
//	// Init GLFW
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", nullptr, nullptr); // Windowed
//	glfwMakeContextCurrent(window);
//
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	// Define the viewport dimensions
//	glViewport(0, 0, screenWidth, screenHeight);
//
//	// Setup some OpenGL options
//	glEnable(GL_MULTISAMPLE);
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS); // Set to always pass the depth test (same effect as glDisable(GL_DEPTH_TEST))
//
//	// Setup and compile our shaders
//	//ShaderManager shader("../../../Path/To/Shaders/advanced.vs", "../../../Path/To/Shaders/advanced.frag");
//	ShaderManager shader("shader//AAV.glsl", "shader//AAF.glsl");
//	hProg = shader.GetProgam();
//	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//	camera.SetExtrinsciParams(cameraPos, cameraFront, cameraUp);
//	camera.SetPerspective(fov, static_cast<float>(screenWidth) / screenHeight, 0.1f, 1000.0f);
//
//#pragma region "object_initialization"
//	// Set the object data (buffers, vertex attributes)
//	GLfloat cubeVertices[] = {
//		// Positions       
//		-0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f, -0.5f,
//		0.5f, 0.5f, -0.5f,
//		0.5f, 0.5f, -0.5f,
//		-0.5f, 0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f, -0.5f, 0.5f,
//		0.5f, -0.5f, 0.5f,
//		0.5f, 0.5f, 0.5f,
//		0.5f, 0.5f, 0.5f,
//		-0.5f, 0.5f, 0.5f,
//		-0.5f, -0.5f, 0.5f,
//
//		-0.5f, 0.5f, 0.5f,
//		-0.5f, 0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f, 0.5f,
//		-0.5f, 0.5f, 0.5f,
//
//		0.5f, 0.5f, 0.5f,
//		0.5f, 0.5f, -0.5f,
//		0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f, 0.5f,
//		0.5f, 0.5f, 0.5f,
//
//		-0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f, 0.5f,
//		0.5f, -0.5f, 0.5f,
//		-0.5f, -0.5f, 0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f, 0.5f, -0.5f,
//		0.5f, 0.5f, -0.5f,
//		0.5f, 0.5f, 0.5f,
//		0.5f, 0.5f, 0.5f,
//		-0.5f, 0.5f, 0.5f,
//		-0.5f, 0.5f, -0.5f 
//	};
//	// Setup cube VAO
//	GLuint cubeVAO, cubeVBO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &cubeVBO);
//	glBindVertexArray(cubeVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glBindVertexArray(0);
//#pragma endregion
//
//	GLuint framebuffer;
//	glGenFramebuffers(1, &framebuffer);
//	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//	GLuint textureColorBufferMultiSampled = generateMultiSampleTexture(4);
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, textureColorBufferMultiSampled, 0);
//	GLuint rbo;
//	glGenRenderbuffers(1, &rbo);
//	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
//	glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8, screenWidth, screenHeight);
//	glBindRenderbuffer(GL_RENDERBUFFER, 0);
//	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
//
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//
//	// Game loop
//	while (!glfwWindowShouldClose(window))
//	{
//		// Set frame time
//		GLfloat currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// Check and call events
//		glfwPollEvents();
//		Do_Movement();
//
//		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//		// Clear the colorbuffer
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// Draw objects
//		glUseProgram(hProg);
//		glm::mat4 model;
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = camera.GetProjMatrix();
//		glUniformMatrix4fv(glGetUniformLocation(hProg, "view"), 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(glGetUniformLocation(hProg, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//		glUniformMatrix4fv(glGetUniformLocation(hProg, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		// Cubes
//		glBindVertexArray(cubeVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		glBindFramebuffer(GL_READ_FRAMEBUFFER, framebuffer);
//		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
//		glBlitFramebuffer(0, 0, screenWidth, screenHeight, 0, 0, screenWidth, screenHeight, GL_COLOR_BUFFER_BIT, GL_NEAREST);
//
//		// Swap the buffers
//		glfwSwapBuffers(window);
//	}
//
//	glfwTerminate();
//	return 0;
//}
//
//GLuint generateMultiSampleTexture(GLuint samples)
//{
//	GLuint texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture);
//	glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples,GL_RGB, screenWidth, screenHeight,GL_TRUE);
//	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
//	return texture;
//}
//
//// This function loads a texture from file. Note: texture loading functions like these are usually 
//// managed by a 'Resource Manager' that manages all resources (like textures, models, audio). 
//// For learning purposes we'll just define it as a utility function.
//GLuint loadTexture(GLchar* path)
//{
//	//Generate texture ID and load texture data 
//	GLuint textureID;
//	glGenTextures(1, &textureID);
//	int width, height;
//	unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
//	// Assign texture to ID
//	glBindTexture(GL_TEXTURE_2D, textureID);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//
//	// Parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	SOIL_free_image_data(image);
//	return textureID;
//
//}
//
//#pragma region "User input"
//
//// Moves/alters the camera positions based on user input
//void Do_Movement()
//{
//	// Camera controls
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
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//
//	if (action == GLFW_PRESS)
//		keys[key] = true;
//	else if (action == GLFW_RELEASE)
//		keys[key] = false;
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	camera.SetFrontBasedOnScreenCoords(xpos, ypos);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	yoffset*= 0.1;
//	if (fov >= 1.0f && fov <= 45.0f)
//		fov -= yoffset;
//	if (fov <= 1.0f)
//		fov = 1.0f;
//	if (fov >= 45.0f)
//		fov = 45.0f;
//	camera.fov = fov;
//}
//
//#pragma endregion