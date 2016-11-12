#include "display.h"
#include <iostream>
#include <string>
#include "glmathtoolkit.h"
Display::Display()
{

}

void Display::createWindow(int width, int height, std::__cxx11::string windowTitle, int openGLMinVersion, int openGLMaxVersion, bool resizeable){
    glfwInit();
    //glfw settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, openGLMaxVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, openGLMinVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, resizeable);
    //TODO: Replace with smart pointer typedef

    this->window.reset(glfwCreateWindow(width, height,windowTitle.c_str(), NULL, NULL));
    glfwMakeContextCurrent(this->window.get());

    //Check if we have a pointer to the window
    if (this->window == nullptr) {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
    }

    //Load OpenGL via GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      std::cout << "Failed to initialize OpenGL context" << std::endl;
    }
    //Setup the OpenGL Viewport
    glViewport(0, 0, width, height);
}

void Display::updateWindow()
{
    glClearColor(clearR,clearG,clearB,clearA);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window.get());
}

void Display::pollEvents() const
{
    glfwPollEvents();
}

bool Display::isClosing() const
{
    return glfwWindowShouldClose(this->window.get());
}

void Display::close() const
{
    glfwTerminate();
}

void Display::setClearColor(float r,float g, float b){
    this->clearR = GLMathToolkit::convertFromRGB(r);
    this->clearG = GLMathToolkit::convertFromRGB(g);
    this->clearB = GLMathToolkit::convertFromRGB(b);
    this->clearA = GLMathToolkit::convertFromRGB(r);
}



Display::~Display()
{
    std::cout << "Display Closing" << std::endl;
}
