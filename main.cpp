#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"
int main()
{

  Display d;
  //GL Clear color in RGB
  d.setClearColor(100, 255, 255);

  //Last step in fake game engine
  d.createWindow(800, 800, "Goood", 3, 3, GL_FALSE);

  //Development shader
  Shader xShader("../untitled/basicshader");


  Vertex verticies[] = {Vertex(glm::vec3(-0.5, -0.5, 0)),
                        Vertex(glm::vec3(0, 0.5, 0)),
                        Vertex(glm::vec3(0.5, -0.5, 0))};

  Mesh foo(verticies,sizeof(verticies) / sizeof(verticies[0]));

  while (!d.isClosing())
  {
    d.pollEvents();
    auto err =  glGetError();
    if(err != GL_NO_ERROR){
        std::cout << err;
    }
    xShader.bindShader();
    foo.draw();
    d.updateWindow();
  }
  d.close();
  return 0;
}
