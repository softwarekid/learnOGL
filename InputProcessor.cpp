#include "InputProcessor.h"


InputProcesor::InputProcesor(const Camera& camera):_camera(camera)
{
}

void InputProcesor::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS)
		_keys[key] = true;
	else if (action == GLFW_RELEASE)
		_keys[key] = false;
}

void InputProcesor::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	_yOffset = yoffset;
}

void InputProcesor::MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	_xPos = xpos;
	_yPos = ypos;
}

void InputProcesor::Do_Movement()
{
	_camera.SetFrontBasedOnScreenCoords(_xPos, _yPos);

	_yOffset*= 0.1;
	float fov = _camera.fov;
	if (fov >= 1.0f && fov <= 45.0f)
		fov -= fov;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;
	_camera.fov = fov;
}
