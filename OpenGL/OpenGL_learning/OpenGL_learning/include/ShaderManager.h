#pragma once 	
#include "stdafx.h"
class ShaderProgram
{
public:
	ShaderProgram( const GLchar* _vertexShaderSource, const GLchar* _fragmentShaderSource);
	GLuint CreateShaderProgram(const GLchar*_vertexShaderSource,const GLchar*_fragmentShaderSource);
	~ShaderProgram();
	GLuint getShaderProgram(){return shaderProgram;}
private:
	GLuint shaderProgram;
};

//const GLchar*  VertexShader={
//	"#version 330 core   \n"
//	"in vec3 vertexColor;\n"
//	"in vec2 texCoord;	\n"
//	"in vec3 position;	\n"
//	"uniform mat4 view;\n"
//	"uniform mat4 model;\n"
//	"uniform mat4 projection;\n"
//	"out vec2 myTexCoord;\n"
//	"out vec3 mycolor;	\n"
//	"void main()		\n"
//	"{                  \n"
//	"	mycolor=vertexColor;\n"
//	"   myTexCoord=texCoord;\n"
//	//	"	gl_Position = model * vec4(position,1.0);\n"
//	//	"	gl_Position =projection*trans * vec4(position,1.0);\n"
//	"	gl_Position =projection*view*model * vec4(position,1.0);\n"
//	//	"	gl_Position = vec4(position,1.0);\n"
//	"}                  \n"
//	"\0					\n"
//};
//const GLchar*  FragmentShader={
//	"#version 330 core   \n"
//	"out vec4 color;	\n"
//	"in vec3 mycolor; \n"
//	"in vec2 myTexCoord;\n"
//	"uniform vec4 ourColor;\n"
//	"uniform sampler2D ourTexture;\n"
//	"uniform sampler2D ourTexture1;\n"
//	"void main()		\n"
//	"{                  \n"
//	//	"  color=vec4(mycolor,1.0);	\n"
//	//	"  color=vec4(1.0,0.0,0.0,1.0);	\n"
//	//	"  color=ourColor;	\n"
//	//	"	myTexCoord=vec2(myTexCoord.x,1.0-myTexCoord.y);\n"
//	"	vec2 input;\n"
//	"	input.x=myTexCoord.x;\n"
//	"	input.y=1.0-myTexCoord.y;\n"
//	//	"   color=texture(ourTexture,input)*0.8+0.2*ourColor;\n"
//	//	"	color=texture(ourTexture,input);\n	"
//	//	"	color=texture(ourTexture,myTexCoord);\n	"
//	//	"	color=texture(ourTexture,myTexCoord)*0.5+texture(ourTexture1,myTexCoord)*0.5;\n	"
//	"	color=mix(texture(ourTexture,myTexCoord),texture(ourTexture1,myTexCoord),1.0);\n	"
//
//	"}                  \n"
//	"\0				\n"
//};
//
