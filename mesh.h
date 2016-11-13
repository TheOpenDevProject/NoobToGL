#ifndef MESH_H
#define MESH_H
#include <glad/glad.h>
#include <glm/glm.hpp>

class Vertex{
public:
    Vertex(const glm::vec3& pos){this->pos = pos;}
private:
protected:
    glm::vec3 pos;
};

class Mesh
{
  public:
    Mesh(Vertex *verticies, unsigned int numVerticies);
    ~Mesh();
    void draw();

  private:
    Mesh(const Mesh &other) = delete;
    void operator=(const Mesh &other) = delete;
    enum
    {
        POSITION_VB,
        NUM_BUFFERS
    };
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif // MESH_H
