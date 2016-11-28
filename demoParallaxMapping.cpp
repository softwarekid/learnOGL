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
//void RenderQuad();
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
//GLfloat height_scale = 0.1;
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
//	// Options
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	// Define the viewport dimensions
//	glViewport(0, 0, screenWidth, screenHeight);
//
//	// Setup some OpenGL options
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS); // Set to always pass the depth test (same effect as glDisable(GL_DEPTH_TEST))
//
//	// Setup and compile our shaders
//	//ShaderManager shader("../../../Path/To/Shaders/advanced.vs", "../../../Path/To/Shaders/advanced.frag");
//	ShaderManager shader("shader//parallaxMapping//parallaxMap_V.glsl", "shader//parallaxMapping//parallaxMap_F.glsl");
//	hProg = shader.GetProgam();
//
//	GLuint diffTexture = loadTexture("texture//bricks2.jpg");
//	GLuint normalTexture = loadTexture("texture//bricks2_normal.jpg");
//	GLuint depthTexture = loadTexture("texture//bricks2_disp.jpg");
//
//	glUseProgram(hProg);
//	glUniform1i(glGetUniformLocation(hProg, "diffuseMap"), 0);
//	glUniform1i(glGetUniformLocation(hProg, "normalMap"), 1);
//	glUniform1i(glGetUniformLocation(hProg, "depthMap"), 2);
//
//	// Light position
//	glm::vec3 lightPos(0.5f, 1.0f, 0.3f);
//
//
//	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//	camera.SetExtrinsciParams(cameraPos, cameraFront, cameraUp);
//	camera.SetPerspective(fov, static_cast<float>(screenWidth) / screenHeight, 0.1f, 1000.0f);
//
//
//#pragma endregion
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		
//		glUseProgram(hProg);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = camera.GetProjMatrix();
//		glUniformMatrix4fv(glGetUniformLocation(hProg, "view"), 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(glGetUniformLocation(hProg, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//		// Render normal-mapped quad
//		glm::mat4 model;
//		//model = glm::rotate(model, (GLfloat)glfwGetTime() * -10, glm::normalize(glm::vec3(1.0, 0.0, 1.0))); // Rotates the quad to show parallax mapping works in all directions
//		glUniformMatrix4fv(glGetUniformLocation(hProg, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		glUniform3fv(glGetUniformLocation(hProg, "lightPos"), 1, &lightPos[0]);
//		glUniform3fv(glGetUniformLocation(hProg, "viewPos"), 1, &camera.pos[0]);
//		glUniform1f(glGetUniformLocation(hProg, "height_scale"), height_scale);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, diffTexture);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, normalTexture);
//		glActiveTexture(GL_TEXTURE2);
//		glBindTexture(GL_TEXTURE_2D, depthTexture);
//		RenderQuad();
//
//		// Swap the buffers
//		glfwSwapBuffers(window);
//	}
//
//	glfwTerminate();
//	return 0;
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
//GLuint quadVAO = 0;
//GLuint quadVBO;
//
//void RenderQuad()
//{
//	if (quadVAO == 0)
//	{
//		glm::vec3 pos1(-1.0, 1.0, 0.0);
//		glm::vec3 pos2(-1.0, -1.0, 0.0);
//		glm::vec3 pos3(1.0, -1.0, 0.0);
//		glm::vec3 pos4(1.0, 1.0, 0.0);
//		// texture coordinates
//		glm::vec2 uv1(0.0, 1.0);
//		glm::vec2 uv2(0.0, 0.0);
//		glm::vec2 uv3(1.0, 0.0);
//		glm::vec2 uv4(1.0, 1.0);
//		// normal vector
//		glm::vec3 nm(0.0, 0.0, 1.0);
//
//		glm::vec3 tangent1, bitangent1;
//		glm::vec3 tangent2, bitangent2;
//		// - triangle 1
//		glm::vec3 edge1 = pos2 - pos1;
//		glm::vec3 edge2 = pos3 - pos1;
//		glm::vec2 deltaUV1 = uv2 - uv1;
//		glm::vec2 deltaUV2 = uv3 - uv1;
//
//		GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//		tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//		tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//		tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//		tangent1 = glm::normalize(tangent1);
//
//		bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//		bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//		bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//		bitangent1 = glm::normalize(bitangent1);
//
//		// - triangle 2
//		edge1 = pos3 - pos1;
//		edge2 = pos4 - pos1;
//		deltaUV1 = uv3 - uv1;
//		deltaUV2 = uv4 - uv1;
//
//		f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//		tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//		tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//		tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//		tangent2 = glm::normalize(tangent2);
//
//
//		bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//		bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//		bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//		bitangent2 = glm::normalize(bitangent2);
//
//
//		GLfloat quadVertices[] = {
//			// Positions            // normal         // TexCoords  // Tangent                          // Bitangent
//			pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//			pos2.x, pos2.y, pos2.z, nm.x, nm.y, nm.z, uv2.x, uv2.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//			pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//
//			pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//			pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//			pos4.x, pos4.y, pos4.z, nm.x, nm.y, nm.z, uv4.x, uv4.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z
//		};
//
//		// Setup plane VAO
//		glGenVertexArrays(1, &quadVAO);
//		glGenBuffers(1, &quadVBO);
//		glBindVertexArray(quadVAO);
//		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)0);
//		glEnableVertexAttribArray(1);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//		glEnableVertexAttribArray(2);
//		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//		glEnableVertexAttribArray(3);
//		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(8 * sizeof(GLfloat)));
//		glEnableVertexAttribArray(4);
//		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(11 * sizeof(GLfloat)));
//	}
//	glBindVertexArray(quadVAO);
//	glDrawArrays(GL_TRIANGLES, 0, 6);
//	glBindVertexArray(0);
//
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
//	yoffset *= 0.1;
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