#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void addColor(GLFWwindow* window);

int main() {

	// Initialize GLFW
	glfwInit();
	// Configure OpenGL (verion and modern functionality)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Only applies to Apple machines
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	// Create window object
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Window", NULL, NULL);
	if (window == NULL) {
		std::cerr << "Failed to create the GLFW window.\n";
		glfwTerminate();
		return -1;
	}
	// Make window the main context on the current thread
	glfwMakeContextCurrent(window);
	// Allow resizing of the window
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Initialize GLAD (OS-specific)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD.\n";
		return -1;
	}

	// Close window only when asked to
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		addColor(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Exit glfw
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// Close the window with ESC
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void addColor(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		glClearColor(0.1f, 0.1f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}