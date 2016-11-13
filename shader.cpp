#include "shader.h"
#include <fstream>
#include <iostream>
Shader::Shader(const std::__cxx11::string &fileName)
{
    m_program = glCreateProgram();
    m_shaders[0] = ShaderTools::createShader(ShaderTools::loadFromFile(fileName + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = ShaderTools::createShader(ShaderTools::loadFromFile(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for (unsigned int i = 0; i < NUM_SHADERS; i++)
    {
        glAttachShader(m_program, m_shaders[i]);
    }

    glBindAttribLocation(m_program, 0, "position");

    glLinkProgram(m_program);
    ShaderTools::checkShaderCompileError(m_program, GL_LINK_STATUS, true, "Error Shader Program Failed to link");

    glValidateProgram(m_program);
    ShaderTools::checkShaderCompileError(m_program, GL_VALIDATE_STATUS, true, "Error: Program failed to validate");
}

Shader::~Shader()
{

    for (unsigned int i = 0; i < NUM_SHADERS; i++)
    {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program);
}

void Shader::bindShader()
{
    glUseProgram(m_program);
}

GLuint ShaderTools::createShader(const std::string &programSource, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);

    if (shader == 0)
    {
        std::cerr << "Error Shader Creation failed" << std::endl;
    }

    const GLchar *shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];

    shaderSourceStrings[0] = programSource.c_str();
    shaderSourceStringLengths[0] = programSource.length();
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);
    ShaderTools::checkShaderCompileError(shader, GL_COMPILE_STATUS, false, "Error, Program failed to compile. Could not create shader");
    return shader;
}

std::string ShaderTools::loadFromFile(const std::string &fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if (file.is_open())
    {
        while (file.good())
        {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else
    {
        std::cerr << "Unable to load shader " << fileName << std::endl;
    }
    return output;
}

void ShaderTools::checkShaderCompileError(GLuint shaderIndex, GLuint flag, bool isProgram, std::string &&errorMessage)
{
    GLint success = 0; //Always assume it failed
    GLchar error[1024] = {0};
    if (isProgram)
    {
        glGetProgramiv(shaderIndex, flag, &success);
    }
    else
    {
        glGetShaderiv(shaderIndex, flag, &success);

        if (success == GL_FALSE)
        {
            if (isProgram)
            {
                glGetProgramInfoLog(shaderIndex, sizeof(error), NULL, error);
            }
            else
            {
                glGetShaderInfoLog(shaderIndex, sizeof(error), NULL, error);
            }
            std::cerr << errorMessage << " " << error << " " << std::endl;
        }
    }
}
