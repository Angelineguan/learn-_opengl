#include "GraphicContext.h"
#include "DrawTriangle.h"

extern GLfloat vertex[];
extern GLfloat vertex1[];

int main()
{
	DrawContext *drawContext=GraphicContext_construct(800,600);
	Triangle triange(drawContext,vertex,18);
	Triangle triange1(drawContext,vertex1,18);

	Vector3 offset(0,0,0);
	triange.setOffset(&offset);
	triange1.setOffset(&offset);
	setGraphicCallbackCollections();
	int width,height;
	
	glfwGetFramebufferSize(drawContext,&width,&height);
	glViewport(0,0,width,height);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	
	glEnable(GL_DEPTH_TEST);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);   
		glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);   
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	while (!glfwWindowShouldClose(drawContext))
	{
		//	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		//glBlendFunc(GL_ONE,GL_ZERO);
		/*glBlendEquation(GL_FUNC_ADD);  
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO); */
		glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
		
		Vector3 offset;
		Color innerColor;
		innerColor.setColor(1.0,0.0,0.0,1.0);
		glfwPollEvents();  
		offset.setZero();
		triange1.setInnerColor(innerColor);
		triange1.setOffset(&offset);
		triange1.draw(true);

		offset.m_x=0.3;
		offset.m_x=-0.3;
		offset.m_z=0.0;
		innerColor.setColor(0.0,1.0,0.0,1.0);
		

		triange.setInnerColor(innerColor);
		triange.setOffset(&offset);
		triange.draw(true);
		//////////////////////////////////////////////////////////////////////////
		glfwSwapBuffers(drawContext);
	}		
	Graphic_destruct();
	return 0;
}