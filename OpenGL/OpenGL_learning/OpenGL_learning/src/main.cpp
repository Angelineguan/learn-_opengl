#include "GraphicContext.h"
#include "DrawTriangle.h"

extern GLfloat vertex[];

int main()
{
	DrawContext *drawContext=GraphicContext_construct(800,600);
	Triangle triange(drawContext,vertex,18);
	Vector3 offset(0,0,0);
	triange.setOffset(&offset);
	setGraphicCallbackCollections();
	int width,height;
	
	glfwGetFramebufferSize(drawContext,&width,&height);
	glViewport(0,0,width,height);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	
	while (!glfwWindowShouldClose(drawContext))
	{
		glDisable(GL_DEPTH_TEST);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
		glEnable(GL_BLEND);
		Vector3 offset;
		Color innerColor;
		innerColor.setColor(1.0,0.0,1.0,1.0);
		glfwPollEvents();  
		glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		offset.setZero();
		triange.setInnerColor(innerColor);
		triange.setOffset(&offset);
		triange.draw(false);

		offset.m_x=0.3;
		offset.m_x=-0.3;
		offset.m_z=0.0;
		innerColor.setColor(1.0,1.0,0.0,1.0);
		triange.setInnerColor(innerColor);
		triange.setOffset(&offset);
		triange.draw(false);
		//////////////////////////////////////////////////////////////////////////
		glfwSwapBuffers(drawContext);
	}		
	Graphic_destruct();
	return 0;
}