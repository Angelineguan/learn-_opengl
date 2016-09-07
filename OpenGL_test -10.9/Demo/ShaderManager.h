
#include <iostream>
using namespace std;
static GLchar*  VertexShader={
	"#version 330 core   \n"
	"layout (location = 0) in vec3 position;\n"
	"layout (location = 2) in vec2 texCoord;	\n"
	
	"out vec2 TexCoord;\n"	
	
	"uniform mat4 model;\n"
	"uniform mat4 view;\n"
	"uniform mat4 projection;	\n"
	"void main()		\n"
	"{                  \n"
	"  gl_Position = projection * view * model * vec4(position, 1.0f);\n"
	"  TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);\n"
	
	"}                  \n"
	"\0					\n"
};
static GLchar*  FragmentShader={
	"#version 330 core   \n"
	"in vec2 TexCoord;	\n"
	"out vec4 color; \n"
	
	"uniform sampler2D ourTexture1;\n"
	"uniform sampler2D ourTexture2;\n"
	"void main()		\n"
	"{                  \n"
	"  color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);	\n"		
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

void updataPara(GLint shaderProgram )
{
	GLint color;
	color = glGetUniformLocation(shaderProgram,"mycolor");
	GLfloat m_alpha=glfwGetTime();
	glUniform4f(color,1.0,0.5,1.0,m_alpha);

}
