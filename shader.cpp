#include "shader.h"
#include <fstream>
#include <iostream>
Shader::Shader(const std::__cxx11::string &fileName)
{
    m_program = glCreateProgram();
    m_shaders[0] = createShader(loadFromFile(fileName + ".vs"),GL_VERTEX_SHADER);
    m_shaders[1] = createShader(loadFromFile(fileName + ".fs"),GL_FRAGMENT_SHADER);

    for(unsigned int i = 0; i < NUM_SHADERS; i++){
        glAttachShader(m_program,m_shaders[i]);
    }

    glLinkProgram(m_program);
    checkShaderCompileError(m_program,GL_LINK_STATUS,true,"Error Shader Program Failed to link");
}

Shader::~Shader(){
    glDeleteProgram(m_program);
}

static GLuint createShader(const std::string& programSource,GLenum shaderType){


}

static std::string loadFromFile(const std::string& fileName){
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open()){
        while(file.good()){
            getline(file,line);
            output.append(line + "\n");
        }
    }else{
        std::cerr << "Unable to load shader " << fileName << std::endl;
    }
    return output;
}

static void checkShaderCompileError(GLuint shaderIndex,GLuint flag, bool isProgram, std::string& errorMessage){
    GLint success = 0; //Always assume it failed
    GLchar error[1024] = {0};
    if(isProgram){
        glGetProgramiv(shaderIndex,flag,&success);
    }else{
        glGetShaderiv(shaderIndex,flag,&success);

        if(success == GL_FALSE){
            if(isProgram){
                glGetProgramInfoLog(shaderIndex,sizeof(error),NULL,error);
            }else{
                glGetShaderInfoLog(shaderIndex,sizeof(error),NULL,error);
            }
            std::cerr << errorMessage << " " << error << " " << std::endl;

        }
    }
}
