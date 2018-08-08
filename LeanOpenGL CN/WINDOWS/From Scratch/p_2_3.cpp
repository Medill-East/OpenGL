//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow*, int width, int height);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char *vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char *fragmentShaderSourceOrange = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//const char *fragmentShaderSourceYellow = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//"}\n\0";
//
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	//////////////////////////////////////////////////////////////////////
//	//Build and compile shader program
//
//	//vertex shader
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	unsigned int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
//	unsigned int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
//
//	unsigned int shaderProgramOrange = glCreateProgram();
//	unsigned int shaderProgramYellow = glCreateProgram();
//
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	glShaderSource(fragmentShaderOrange, 1, &fragmentShaderSourceOrange, NULL);
//	glCompileShader(fragmentShaderOrange);
//
//	glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSourceYellow, NULL);
//	glCompileShader(fragmentShaderYellow);
//	
//	// link first program object
//	glAttachShader(shaderProgramOrange, vertexShader);
//	glAttachShader(shaderProgramOrange, fragmentShaderOrange);
//	glLinkProgram(shaderProgramOrange);
//
//	// link second
//	glAttachShader(fragmentShaderYellow, vertexShader);
//	glAttachShader(fragmentShaderYellow, fragmentShaderYellow);
//	glLinkProgram(fragmentShaderYellow);
//
//#pragma region check for errors
//
//
//
//	//check for shader compile errors
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShaderOrange, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENTORANGE::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENTYELLOW::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	//check for linking errors
//	glGetProgramiv(shaderProgramOrange, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(fragmentShaderOrange, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAMORANGE::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//	glGetProgramiv(fragmentShaderYellow, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAMYELLOW::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//#pragma endregion
//
//	//set up vertex data
//	float firstTriangle[] = {
//		0.5f,  0.5f, 0.0f,  // top right
//		0.5f, -1.0f, 0.0f,  // bottom right
//		-0.5f, -0.5f, 0.0f,  // bottom left
//	};
//
//	float secondTriangle[] = {
//		-0.5f,  0.5f, 0.0f,   // top left 
//		0.5f,1.0f,0.0f,
//		-0.5f,-0.5f,0.0f
//		//1.0f,1.0f,0.0f,
//		//1.0f,-1.0f,0.0f,
//		//-1.0f,-1.0f,0.0f,
//		//-1.0f,1.0f,0.0f
//	};
//
//	unsigned int VBOs[2], VAOs[2];
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//
//	// first triangle
//	//bind vertex array object
//	glBindVertexArray(VAOs[0]);
//	//set vertex buffers
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//	//configure vertex attrivutes(s)
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//////////////////////////////////////////////////////////////////////
//	// second triangle
//	//bind vertex array object
//	glBindVertexArray(VAOs[1]);
//	//set vertex buffers
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//	//configure vertex attrivutes(s)
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//////////////////////////////////////////////////////////////////////
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//
//	//////////////////////////////////////////////////////////////////////
//	// render loop
//	while (!glfwWindowShouldClose(window))
//	{
//		//input
//		processInput(window);
//
//		//render
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// first triangle
//		//use shader
//		glUseProgram(shaderProgramOrange);
//		//bind VAO
//		glBindVertexArray(VAOs[0]);
//		//draw
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		// second triangle
//		//use shader
//		glUseProgram(fragmentShaderYellow);
//		//bind VAO
//		glBindVertexArray(VAOs[1]);
//		//draw
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		//glfw:swap & poll
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(2, VAOs);
//	glDeleteBuffers(2, VBOs);
//	////delete shaderObject
//	//glDeleteShader(vertexShader);
//	//glDeleteShader(fragmentShaderOrange);
//	//glDeleteShader(fragmentShaderYellow);
//
//
//
//	//glfw: terminate,clear
//	glfwTerminate();
//	return 0;
//
//}
////////////////////////////////////////////////////////////////////////
//
//void framebuffer_size_callback(GLFWwindow*, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//}