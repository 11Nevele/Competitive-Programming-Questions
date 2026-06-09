#ifndef DRAWWINDOW_HPP
#define DRAWWINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace DrawWindow
{

	void framebuffer_size_callback(GLFWwindow*, int, int);
	void ProcessInput(GLFWwindow*);

	int DrawWindow();

}

#endif