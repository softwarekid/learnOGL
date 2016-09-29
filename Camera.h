#ifndef camera_h__
#define camera_h__
#include <glm/glm.hpp>

class Camera
{
public:
	Camera() :  pos(glm::vec3(0.0f, 0.0f, 0.0f)),
				center(glm::vec3(0.0f, 0.0f, -1.0f)),
				up(glm::vec3(0.0f, 1.0f, 0.0f)),
				fov(0),aspect(0),near(0),far(0)
	{}
	void SetExtrinsciParams(const glm::vec3& pos_, const glm::vec3& center_, const glm::vec3& up_ );

	void SetPerspective(float fov_, float aspect_, float near_, float far_);
	
	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjMatrix() const;

	// it is a rather simple idea to compare the offset of cursor movement. Currently only works on front(0,0,-1), 
	// which is true for most situations
	// More physically accurate method should refer to something like ray cating.
	void SetFrontBasedOnScreenCoords(double xPos, double yPos);
	void MoveForward(float speed);
	void MoveRight(float speed);
	float fov;
	glm::vec3 pos;
private:

	glm::vec3 center;
	glm::vec3 up;

	float aspect;
	float near;
	float far;

	glm::vec3 frontDir;

	float yaw = 0;
	float pitch = 0;
	float lastX = 0 ;
	float lastY = 0;
	bool firstMouse = true;
};

#endif