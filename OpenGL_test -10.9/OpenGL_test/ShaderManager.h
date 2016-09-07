#pragma  once
#include "CallBackFunction.h"
const GLchar*  VertexShader={
	"#version 330 core   \n"
	"in vec3 vertexColor;\n"
	"in vec2 texCoord;	\n"
	"in vec3 position;	\n"
	"uniform mat4 view;\n"
	"uniform mat4 model;\n"
	"uniform mat4 projection;\n"
	"out vec2 myTexCoord;\n"
	"out vec3 mycolor;	\n"
	"void main()		\n"
	"{                  \n"
	"	mycolor=vertexColor;\n"
	"   myTexCoord=texCoord;\n"
//	"	gl_Position = model * vec4(position,1.0);\n"
//	"	gl_Position =projection*trans * vec4(position,1.0);\n"
	"	gl_Position =projection*view*model * vec4(position,1.0);\n"
//	"	gl_Position = vec4(position,1.0);\n"
	"}                  \n"
	"\0					\n"
};
const GLchar*  FragmentShader={
	"#version 330 core   \n"
	"out vec4 color;	\n"
	"in vec3 mycolor; \n"
	"in vec2 myTexCoord;\n"
	"uniform vec4 ourColor;\n"
	"uniform sampler2D ourTexture;\n"
	"uniform sampler2D ourTexture1;\n"
	"void main()		\n"
	"{                  \n"
//	"  color=vec4(mycolor,1.0);	\n"
//	"  color=vec4(1.0,0.0,0.0,1.0);	\n"
//	"  color=ourColor;	\n"
//	"	myTexCoord=vec2(myTexCoord.x,1.0-myTexCoord.y);\n"
	"	vec2 input;\n"
	"	input.x=myTexCoord.x;\n"
	"	input.y=1.0-myTexCoord.y;\n"
//	"   color=texture(ourTexture,input)*0.8+0.2*ourColor;\n"
//	"	color=texture(ourTexture,input);\n	"
//	"	color=texture(ourTexture,myTexCoord);\n	"
//	"	color=texture(ourTexture,myTexCoord)*0.5+texture(ourTexture1,myTexCoord)*0.5;\n	"
	"	color=mix(texture(ourTexture,myTexCoord),texture(ourTexture1,myTexCoord),1.0);\n	"

	"}                  \n"
	"\0				\n"
};

GLuint  CreatShaderPrograme(const GLchar*  vertexShaderSource, const GLchar*  fragmentShaderSource)
{
	GLuint verteshader; 
	verteshader=glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(verteshader,1,&vertexShaderSource,NULL);
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
	glShaderSource(fragmentshader,1,&fragmentShaderSource,NULL);
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

