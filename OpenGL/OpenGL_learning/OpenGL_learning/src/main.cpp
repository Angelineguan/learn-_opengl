#include "stdafx.h"
#include "GraphicContext.h"

int main()
{
	DrawContext *drawContext=GraphicContext_construct(800,600);

	int width,height;
	glfwGetFramebufferSize(drawContext,&width,&height);
	glViewport(0,0,width,height);
	while (!glfwWindowShouldClose(drawContext))
	{
		
		glEnable(GL_VIEWPORT);
		glViewport(0,0,width/2,height/2);
		glClearColor(0,1.0f,0.1f,0.8f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		glfwSwapBuffers(drawContext);
	}
	Graphic_destruct();
	return 0;
}