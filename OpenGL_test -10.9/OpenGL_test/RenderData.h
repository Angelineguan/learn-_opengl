#pragma  once
#include "ShaderManager.h"
#include <GL/SOIL.h>
#include "CallBackFunction.h"
#include "FrameBufferManager.h"

static GLfloat vertex1[]={
	0.5f,0.5f, 0.0f,  // Bottom Left
	0.5f,-0.5f, 0.0f,  // Bottom Right
	-0.5f,-0.5f, 0.0f,   // Top Left
	-0.5f,0.5f, 0.0f , // Top Right	 
	0.5f,0.5f, 0.0f,  // Bottom Left
	-0.5f,-0.5f, 0.0f   // Top Left
};
GLfloat vertex[] = {
	-0.5f, -0.5f, -0.5f,  
	0.5f, -0.5f, -0.5f, 
	0.5f,  0.5f, -0.5f,  
	0.5f,  0.5f, -0.5f,  
	-0.5f,  0.5f, -0.5f,  
	-0.5f, -0.5f, -0.5f,  

	-0.5f, -0.5f,  0.5f, 
	0.5f, -0.5f,  0.5f,  
	0.5f,  0.5f,  0.5f,  
	0.5f,  0.5f,  0.5f,  
	-0.5f,  0.5f,  0.5f,  
	-0.5f, -0.5f,  0.5f,  

	-0.5f,  0.5f,  0.5f, 
	-0.5f, -0.5f, -0.5f,  
	-0.5f, -0.5f, -0.5f,  
	-0.5f, -0.5f,  0.5f,  
	-0.5f,  0.5f,  0.5f,  

	0.5f,  0.5f,  0.5f,  
	0.5f,  0.5f, -0.5f,  
	0.5f, -0.5f, -0.5f,  
	0.5f, -0.5f, -0.5f,  
	0.5f, -0.5f,  0.5f,  
	0.5f,  0.5f,  0.5f,  

	-0.5f, -0.5f, -0.5f, 
	0.5f, -0.5f, -0.5f,  
	0.5f, -0.5f,  0.5f,  
	0.5f, -0.5f,  0.5f,  
	-0.5f, -0.5f,  0.5f,  
	-0.5f, -0.5f, -0.5f,  

	-0.5f,  0.5f, -0.5f,  
	0.5f,  0.5f, -0.5f,  
	0.5f,  0.5f,  0.5f,  
	0.5f,  0.5f,  0.5f,  
	-0.5f,  0.5f,  0.5f,  
	-0.5f,  0.5f, -0.5f,  
};
static GLint index[]={
	0,1,3,
	1,2,3
};
static GLfloat vertexColor[]={
	1.0,0.0,1.0,
	1.0,1.0,0.0,
	0.2,0.9,1.0,
	0.3,1.0,0.5,

	1.0,0.0,1.0,
	1.0,1.0,0.0,
	0.2,0.9,1.0,
	0.3,1.0,0.5,

	1.0,0.0,1.0,
	1.0,1.0,0.0,
	0.2,0.9,1.0,
	0.3,1.0,0.5,

	1.0,0.0,1.0,
	1.0,1.0,0.0,
	0.2,0.9,1.0,
	0.3,1.0,0.5,

	1.0,0.0,1.0,
	1.0,1.0,0.0,
	0.2,0.9,1.0,
	0.3,1.0,0.5,

	1.0,0.0,1.0,
	1.0,1.0,0.0,
	0.2,0.9,1.0,
	0.3,1.0,0.5
};
static GLfloat texCoord[]={
	1.0f,1.0f,
	1.0f,0.0f,
	0.0f,0.0f,
	0.0,1.0f,
	1.0f,1.0f,
	0.0f,0.0f
};
glm::vec3 cubePositions[] = {
	glm::vec3( 0.0f,  0.0f,  0.0f),
	glm::vec3( 0.3f,  5.0f, -15.0f),
	glm::vec3(-0.4f, -0.2f, -0.5f),
	glm::vec3(0.4f, -0.2f, -0.5f),
	glm::vec3(0.4f, 0.2f, -0.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3( 1.3f, -2.0f, -2.5f),
	glm::vec3( 1.5f,  2.0f, -2.5f),
	glm::vec3( 1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
};

GLuint vao;
GLuint vbo;
GLuint ebo;
GLuint texurebo;
GLuint colorbo;
GLuint texure;
GLuint texure1;
GLuint ShaderPrograme;
GLint colorLocation;
GLint positionLocation;
GLint texcoorLocation;
GLint textureLocation;
GLint textureLocation1;
GLint transLocation;
extern  GLfloat WIDTH = 800.0f;
extern  GLfloat HEIGHT = 600.0f;
extern GLfloat TEXwidth=WIDTH/2;
extern GLfloat TEXheight=HEIGHT/2;
int imageWidth,imageHeight;

glm::mat4  trans;

FBO myfbo;

void initialData()
{
	myfbo=CreateFBO();
	ShaderPrograme=	CreatShaderPrograme(VertexShader,FragmentShader);
	
	unsigned char* image=SOIL_load_image("Chrysanthemum.jpg",&imageWidth,&imageHeight,0,SOIL_LOAD_RGBA);
	glGenTextures(1,&texure);
	glBindTexture(GL_TEXTURE_2D,texure);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,imageWidth,imageHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D,0);

	unsigned char* image1=SOIL_load_image("111.jpg",&imageWidth,&imageHeight,0,SOIL_LOAD_RGBA);
	glGenTextures(1,&texure1);
	glBindTexture(GL_TEXTURE_2D,texure1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,imageWidth,imageHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,image1);
	SOIL_free_image_data(image1);
	glBindTexture(GL_TEXTURE_2D,0);

	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertex1),vertex1,GL_STATIC_DRAW);

	glGenBuffers(1,&colorbo);
	glBindBuffer(GL_COLOR_ARRAY,colorbo);
	glBufferData(GL_COLOR_ARRAY,sizeof(vertexColor),vertexColor,GL_STATIC_DRAW);

	glGenBuffers(1,&ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(index),index,GL_STATIC_DRAW);

	colorLocation=glGetAttribLocation(ShaderPrograme,"vertexColor");
	glVertexAttribPointer(colorLocation,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(colorLocation);

	positionLocation=glGetAttribLocation(ShaderPrograme,"position");
	glVertexAttribPointer(positionLocation,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(positionLocation);

	glGenBuffers(1,&texurebo);
	glBindBuffer(GL_ARRAY_BUFFER,texurebo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(texCoord),texCoord,GL_STATIC_DRAW);

	texcoorLocation=glGetAttribLocation(ShaderPrograme,"texCoord");
	glVertexAttribPointer(texcoorLocation,2,GL_FLOAT,GL_FALSE,2*sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(texcoorLocation);
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,texure);
	textureLocation=glGetUniformLocation(ShaderPrograme,"ourTexture");
	glUniform1i(textureLocation,0);	
	glActiveTexture(GL_TEXTURE0+1);
	glBindTexture(GL_TEXTURE_2D,texure1);
	textureLocation1=glGetUniformLocation(ShaderPrograme,"ourTexture1");
	glUniform1i(GL_TEXTURE_2D,1);

	glBindVertexArray(0);
}		
void updateCamera()
{
	GLfloat timeValue = glfwGetTime();    
	GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
	GLint vertexColorLocation = glGetUniformLocation(ShaderPrograme, "ourColor");
	glUniform4f(vertexColorLocation, 1.0f, 0.0f, greenValue, 0.5f);

	glm::mat4 viewMatrix=Camera::GetInstance()->getLookAt();
	GLint transformLoc = glGetUniformLocation(ShaderPrograme, "view");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE,glm::value_ptr(viewMatrix));

	glm::mat4 projection;
	projection=Camera::GetInstance()->GetPersPective();
	GLint projectionLoc=glGetUniformLocation(ShaderPrograme,"projection");
	glUniformMatrix4fv(projectionLoc ,1 ,GL_FALSE,glm::value_ptr(projection));	
}
void SetRenderState()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POLYGON_MODE);
	//glPolygonMode(GL_FRONT ,GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glViewport(0, 0, WIDTH, HEIGHT);
	glLineWidth(3.0f);
	glPointSize(50.0f);	
}
void renderToTexture()
{
	glBindFramebuffer(GL_FRAMEBUFFER,myfbo.fbohandle);
	glClearColor(1.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0,0,TEXwidth,TEXwidth);	
#if 1
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D,texure1);
#endif	
	for (int i=0;i<10;i++)
	{
		glm::mat4 model;
		model=glm::translate(model,cubePositions[i]);
		model*=Camera::GetInstance()->GetTranslateMatrix();
		model*=Camera::GetInstance()->GetRotateMatrix();
		GLfloat angle=20.0f*i;
	 	model*=Camera::GetInstance()->GetScaleMatrix();
		GLint modelLocation=glGetUniformLocation(ShaderPrograme,"model");
		glUniformMatrix4fv(modelLocation,1,GL_FALSE,glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES,0,6);
	}
	glBindFramebuffer(GL_FRAMEBUFFER,0);
}
void renderToDefaultFBO()
{
	glViewport(0,0,WIDTH,HEIGHT);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,myfbo.depthbufferhandle);
	for (int i=0;i<5;i++)
	{
		glm::mat4 model;
		model=glm::translate(model,cubePositions[i]);
		model*=Camera::GetInstance()->GetTranslateMatrix();
		model*=Camera::GetInstance()->GetRotateMatrix();
		GLfloat angle=20.0f*i;
		model*=Camera::GetInstance()->GetScaleMatrix();	
		GLint modelLocation=glGetUniformLocation(ShaderPrograme,"model");
		glUniformMatrix4fv(modelLocation,1,GL_FALSE,glm::value_ptr(model));
		
		glDrawArrays(GL_TRIANGLES,0,6);
	}
}
void RenderScene()
{	
	
	glUseProgram(ShaderPrograme);
	glBindVertexArray(vao);
	updateCamera();	
	//start to render things on fbo and default fbo
	renderToTexture();
	renderToDefaultFBO();
	
	//-----------------------------------------
	glBindVertexArray(0);
	glBindFramebuffer(GL_FRAMEBUFFER,0);
}

