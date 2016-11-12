#include <iostream>
#include "display.h"
#include "shader.h"
int main() {

    Display d;
    //GL Clear color in RGB
    d.setClearColor(66,244,104);



    //Last step in fake game engine
    d.createWindow(800,800,"Goood",3,3,GL_FALSE);

    //Development shader
    Shader xShader("basicshader");
    xShader.bindShader();


    while(!d.isClosing()){
      d.pollEvents();
      d.updateWindow();
    }
    d.close();
  return 0;
}



