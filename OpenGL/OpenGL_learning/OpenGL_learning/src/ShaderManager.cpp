#include "ShaderManager.h"
#include "stdafx.h"
ShaderProgram::ShaderProgram( const GLchar* _vertexShaderSource, const  GLchar* _fragmentShaderSource)
{
	shaderProgram=CreateShaderProgram(_vertexShaderSource,_fragmentShaderSource);
}
GLuint ShaderProgram::CreateShaderProgram(const GLchar*_vertexShaderSource,const GLchar*_fragmentShaderSource)
{
	GLuint verteshader; 
	verteshader=glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(verteshader,1,&_vertexShaderSource,NULL);
	glCompileShader(verteshader);
	GLint success=0;
	GLchar infoLog[512];
	glGetShaderiv(verteshader,GL_COMPILE_STATUS,&success);
	if (!success)
	{
		glGetShaderInfoLog(verteshader,512,NULL,infoLog);
		cout<<"ERROR::verteshader::vertext::compile failed\n"<<infoLog<<endl;
	}
	/////////
	GLuint fragmentshader;
	fragmentshader=glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader,1,&_fragmentShaderSource,NULL);
	glCompileShader(fragmentshader);
	glGetShaderiv(fragmentshader,GL_COMPILE_STATUS,&success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentshader,512,NULL,infoLog);
		cout<<"ERROR::fragmentshader::vertext::compile failed\n"<<infoLog<<endl;
	}

	GLuint shaderProgram;
	shaderProgram=glCreateProgram();
	glAttachShader(shaderProgram,verteshader);
	glAttachShader(shaderProgram,fragmentshader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
		cout<<"ERROR::SHADER_Progarem_GL_LINK_STATUS\n"<<infoLog<<endl;
	}
	glDeleteShader(verteshader);
	glDeleteShader(fragmentshader);
	return shaderProgram;
}
ShaderProgram::~ShaderProgram()
{
	cout<<"we are now delete the shader program"<<endl;
	glDeleteProgram(shaderProgram);
}
