#pragma  once
#include "stdafx.h"
typedef GLFWwindow  DrawContext;

GLFWwindow* GraphicContext_construct(int width,int height)	;

DrawContext* getGraphicContext();

void Graphic_destruct();


