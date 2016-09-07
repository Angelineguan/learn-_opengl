#pragma  once
#include "CallBackFunction.h"
 GLfloat TEXwidth;
 GLfloat TEXheight;
 struct FBO
 {
	 GLuint  fbohandle;
	 GLuint	 colorbufferhandle;
	 GLuint  depthbufferhandle;

 };
FBO  CreateFBO()
{
	FBO myfbo;
	glGenFramebuffers(1,&myfbo.fbohandle);
	glBindFramebuffer(GL_FRAMEBUFFER,myfbo.fbohandle);	
	glBindFramebuffer(GL_FRAMEBUFFER,0);
	glDeleteFramebuffers(1,&myfbo.fbohandle);

	glGenTextures(1,&myfbo.colorbufferhandle);
	glBindTexture(GL_TEXTURE_2D,myfbo.colorbufferhandle);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,TEXwidth,TEXheight,0,GL_RGBA,GL_UNSIGNED_BYTE,NULL);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D,0);
	glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,myfbo.colorbufferhandle,0);

	glGenRenderbuffers(1,&myfbo.depthbufferhandle);
	glBindRenderbuffer(GL_RENDERBUFFER,myfbo.depthbufferhandle);
	glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH24_STENCIL8,TEXwidth,TEXheight);
	glBindRenderbuffer(GL_RENDERBUFFER,0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,GL_RENDERBUFFER,myfbo.depthbufferhandle);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER==GL_FRAMEBUFFER_COMPLETE))
	{
		cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << endl;
	}
	glBindFramebuffer(GL_FRAMEBUFFER,0);
	return myfbo;	
}