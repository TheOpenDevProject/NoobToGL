#ifndef DISPLAY_H
#define DISPLAY_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <memory>
#include <iostream>
struct glfwDeleter{
    void operator()(GLFWwindow *wnd){
        std::cout << "Destroying GLFW Window Context" << std::endl;
        glfwDestroyWindow(wnd);
    }
};

class Display
{
public:
    Display();
    void createWindow(int width, int height, std::string windowTitle, int openGLMinVersion, int openGLMaxVersion,bool resizeable);
    void setClearColor(float r,float g, float b);
    void updateWindow();
    void pollEvents() const;
    bool isClosing() const;
    void close() const;
    ~Display();
private:
    std::unique_ptr<GLFWwindow,glfwDeleter> window;
    float clearR = 1.0f,clearG = 1.0f,clearB = 1.0f,clearA = 1.0f;

};

#endif // DISPLAY_H
