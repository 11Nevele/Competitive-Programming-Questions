#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>



	void framebuffer_size_callback(GLFWwindow*, int, int);
	void ProcessInput(GLFWwindow*);

	int DrawTriangle();

	unsigned int AddShader(const char*, GLenum);


#endif