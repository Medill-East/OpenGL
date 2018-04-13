//
//  SHADER.h
//  Glitter
//
//  Created by Medill East on 2018/4/13.
//

#ifndef SHADER_h
#define SHADER_h

#include <glad/glad.h>;

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    // 程序ID
    unsigned int ID;
    
    // 构造器读取并构建着色器
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
    {
        //1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try {
            //open files
            fShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderstream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderstream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderstream.str();
        } catch (std::ifstream::failure e) {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        
        // 2. compile shaders
        unsigned int vertex,fragment;
        int success;
        char infoLog[512];
        // vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex,1,&vShaderCode,NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex,"VERTEX");
        // fragment shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment,1,&fShaderCode,NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment,"FRAGMENT");
        // shader program
        ID = glCreateProgram();
        glAttachShader(ID,vertex);
        glAttachShader(ID,fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");
        // delete the shaders
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }
    // 使用/激活程序
    void use()
    {
        glUseProgram(ID);
    }
    // uniform 工具函数
    void setBool(const std::string &name,bool value) const
    {
        glUniform1i(glGetUniformLocation(ID,name.c_str()),(int)value);
    }
    void setInt(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID,name.c_str()),value);
    }
    void setFloat(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID,name.c_str()),value);
    }
    
private:
    void checkCompileErrors(unsigned int shader,std::string type);

};
#endif /* SHADER_h */
