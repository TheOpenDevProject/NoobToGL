#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glad/glad.h>

//The lessons I was following abused the hell out of static which is silly because C++ has free functions and namespaces and static is not fre
namespace ShaderTools{
    std::string loadFromFile(const std::string& fileName);
    void checkShaderCompileError(GLuint shaderIndex, GLuint flag, bool isProgram, std::string &&errorMessage);
    GLuint createShader(const std::string& programSource,GLenum shaderType);
}

class Shader
{
public:
    Shader(const std::string& fileName);
    ~Shader();
    void bindShader();
private:
    //Helper Methods (This might be bad to make static, when building engine after learning consider a propper loader pattern).
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other) = delete;
    void operator=(const Shader& other) = delete;
    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
};

#endif // SHADER_H
