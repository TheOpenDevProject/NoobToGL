#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glad/glad.h>
class Shader
{
public:
    Shader(const std::string& fileName);
    ~Shader();
    void bindShader();
private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other) = delete;
    void operator=(const Shader& other) = delete;
    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
};

#endif // SHADER_H
