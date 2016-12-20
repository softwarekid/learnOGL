#ifndef input_processor_h
#define  input_processor_h

#include <GLFW/glfw3.h>

class InputProcesor
{
public:
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void Do_Movement();

private:
	bool keys[1024];
};


#endif //input_processor_h
