/**
*  \file ExampleOpenGL.cpp
*  \brief This is an example project for using OpenGL API. In order to fully
*  use OpenGL, we need to use both GLFW and GLEW:
*  GLFW - Handles window creation and mouse/keyboard input events.
*  GLEW - Access modern OpenGL API functions.
*/

#include <iostream>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>

// Width and height of application.
// GLint is compatible across different OS's, so we don't use int.
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    // Initialize GLFW.
    glfwInit();

    // Set OpenGL to version 3.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // GLFW_OPENGL_CORE_PROFILE uses the new OpenGL features.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Mac compatibility.
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Resizable?
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* Window = glfwCreateWindow(WIDTH, HEIGHT, "GameEngine", nullptr, nullptr);

    // Gets the screen resolution.
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(Window, &screenWidth, &screenHeight);

    if (Window == nullptr)
    {
        std::cout << "Failed to create window." << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(Window);

    // So GLEW knows to use a modern approach.
    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;

        return EXIT_FAILURE;
    }

    // Set OpenGL viewport.
    glViewport(0, 0, screenWidth, screenHeight);

    // Game loop.
    while (!glfwWindowShouldClose(Window))
    {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw OpenGL stuff.
        glfwSwapBuffers(Window);
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}