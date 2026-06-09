#include "triangle.hpp"
#include "shaders.hpp"

float vertices[] =
{
	0.0f,-0.5f,0.0f,
	-0.5f,0.5f,0.0f,
	0.0f,0.5f,0.0f,
	-0.5f,-0.5f,0.0f

};
unsigned triangle1[] =
{
	0,1,2,
	3,0,1
};
unsigned triangle2[] =
{
	3,0,1
};

//return shader id
unsigned int AddShader(const char* src, GLenum type)
{
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);

	int sucess;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &sucess);
	if (!sucess)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR SHADER COMPILE\n" << infoLog << "\n";
		return -1;
	}
	return shader;

}

int DrawTriangle()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//init window
	GLFWwindow* window = glfwCreateWindow(800, 600, "TriangleOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Fail to Create Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//load glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return -1;
	}

	//add shader
	unsigned vertexShader = AddShader(vertexShaderSource, GL_VERTEX_SHADER);
	unsigned fragmentRedShader = AddShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
	unsigned fragmentGreenShader = AddShader(fragmentShaderGreenSource, GL_FRAGMENT_SHADER);

	unsigned shaderRedProgram = glCreateProgram();
	unsigned shaderGreenProgram = glCreateProgram();
	glAttachShader(shaderRedProgram, vertexShader);
	glAttachShader(shaderRedProgram, fragmentRedShader);
	glLinkProgram(shaderRedProgram);

	glAttachShader(shaderGreenProgram, vertexShader);
	glAttachShader(shaderGreenProgram, fragmentGreenShader);
	glLinkProgram(shaderGreenProgram);


	glDeleteShader(vertexShader);
	glDeleteShader(fragmentRedShader);
	glDeleteShader(fragmentGreenShader);


	//load triangle
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int triangle1EBO, triangle2EBO;
	glGenBuffers(1, &triangle1EBO);
	glGenBuffers(1, &triangle2EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle1EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle2EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);


	//VAO ???
	unsigned VAO1, VAO2;
	glGenVertexArrays(1, &VAO1);
	glGenVertexArrays(1, &VAO2);

	//bind triangle1
	glBindVertexArray(VAO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),(void*)(sizeof(unsigned) * 0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle1EBO);

	////bind triangle2
	//glBindVertexArray(VAO2);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle2EBO);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	


	glClearColor(0.5f, 0.5f, 0, 0);
	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO1);
		glUseProgram(shaderRedProgram);
		
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		glUseProgram(shaderGreenProgram);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(sizeof(unsigned) * 3));
	


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteProgram(shaderRedProgram);
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
};

void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	return;
}

