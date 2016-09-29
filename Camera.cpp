#include "Camera.h""
#include "gl/glew.h"
#include <glm/gtc/matrix_transform.hpp>


void Camera::SetExtrinsciParams(const glm::vec3& pos_, const glm::vec3& center_, const glm::vec3& up_)
{
	pos = pos_;
	center = center_;
	up = up_;
	frontDir = center - pos;
}

void Camera::SetPerspective(float fov_, float aspect_, float near_, float far_)
{
	fov = fov_;
	aspect = aspect_;
	near = near_;
	far = far_;
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(pos, pos + frontDir, up);
}

glm::mat4 Camera::GetProjMatrix() const
{
	return glm::perspective(fov, aspect, near, far);
}

void Camera::SetFrontBasedOnScreenCoords(double xPos, double yPos)
{
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	GLfloat xoffset =  lastX - xPos;
	// glfw 的视窗是以左上角为原点的。
	GLfloat yoffset = lastY - yPos;
	lastX = xPos;
	lastY = yPos;

	GLfloat sensitivity = 0.1;
	xoffset *= sensitivity;
	yoffset *= sensitivity;


	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;

	front.x = -sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = -cos(glm::radians(yaw)) * cos(glm::radians(pitch));

	frontDir = glm::normalize(front);
}

void Camera::MoveForward(float speed)
{
	pos += speed * frontDir;
}

void Camera::MoveRight(float speed)
{
	pos += glm::normalize(glm::cross(frontDir, up)) * speed;
}