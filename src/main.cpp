#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
void processInput (GLFWwindow* window);
int main()
{
    //Initialization and setting the version and mode.
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //only for macOS we need to enable forward_Compatiblity
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //creating a window from GLFW
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //creating the context (which is the current OpenGL state).
    glfwMakeContextCurrent(window);

    //checking if GLAD is initialized correctly.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //specifying how much W & H of the window we created we want for rendering.
    glViewport(0, 0, 800, 600);


    //closing the window on clicking.
    while (!glfwWindowShouldClose(window))
    {
        processInput (window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    //Release/Clean all the buffers that is stored for GLFW.
    glfwTerminate();
    return 0;
}


//processing Input from Keyboard
void processInput   (GLFWwindow* window)
{
    //if pressing escape, close that window
    if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window,true);

}