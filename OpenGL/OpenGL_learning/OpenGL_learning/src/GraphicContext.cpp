
#include "GraphicContext.h"

DrawContext *g_context;

DrawContext * GraphicContext_construct(int width,int height)
{
	int initialState=glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	g_context=glfwCreateWindow(800,600,"Learn OpenGL",nullptr,nullptr);
	if (!g_context)
	{
		cout<<"create window failed"<<endl;
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(g_context);

	glewExperimental=GL_TRUE;
	if (glewInit()!=GLEW_OK)
	{
		cout<<" failed to initialize the GLEW"<<endl;
		glfwTerminate();
		return nullptr;
	}
	return g_context;
}

DrawContext*getGraphicContext()
{
	return g_context;
}

void Graphic_destruct()
{
	DrawContext*o=g_context;
	glfwDestroyWindow(o);
	glfwTerminate();
}
