#ifndef input_processor_h
#define  input_processor_h

#include <GLFW/glfw3.h>
#include "Camera.h"

class InputProcesor
{
public:
	InputProcesor(const Camera& camera);
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
	void Do_Movement();
private:
	static bool _keys[1024];
	static double _yOffset;
	static double _xPos, _yPos;
	Camera _camera;
};


#endif //input_processor_h
