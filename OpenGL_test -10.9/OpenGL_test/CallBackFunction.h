
#pragma  once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "UpdataCamera.h"
using namespace std;
GLboolean is_clear_color=GL_FALSE;
static int press_count=0;
static GLfloat m_alpha=1.0;
void do_movement();
glm::vec3 cameraPos=glm::vec3(0.0,0.0,1.0);
glm::vec3 cameraFront=glm::vec3(0.0,0.0,-1.0);
glm::vec3 cameraUp=glm::vec3(0.0,1.0,0.0);
 GLfloat DeltaTime;
  bool keys[1024];
//   GLfloat Camera::GetInstance()->fov=45;
GLfloat zoomscale=0.06;
GLfloat rotateAngle=0;
GLfloat step_x=0.1,step_y=0.1;
GLfloat stepLength=0.01;
void key_callback_updataCamara(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow *window,double xpos,double ypos);
void scroll_callback(GLFWwindow*window,double xpos,double ypos);
void mouse_callback1(GLFWwindow*window,int action,int key,int mode);
void zoomin();
void zoomout();
void scaleToMin();
void scaleToMax();
void rotateZ_clockwise();
void rotateZ_anticlockwise();
void translate_step();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key==GLFW_KEY_RIGHT &&action==GLFW_PRESS)
	{
		
		glfwSetWindowShouldClose(window,GL_FALSE);
		is_clear_color=GL_TRUE;
		cout<<"we are going to die"<<endl;
			glfwTerminate();
	}
}
void transfromColor(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key==GLFW_KEY_SPACE &&action==GLFW_PRESS)
	{
		//	glfwWindowShouldClose(window,GL_TRUE);
		is_clear_color=GL_TRUE;
		press_count++;
		
	//	cout<<"press_count="<<press_count<<endl;
		if (press_count>5)
		{
			press_count=0;
		}
	}
	if (key==GLFW_KEY_ESCAPE)
	{
		glfwWindowShouldClose(window);
	}
	

}

void setCallBackFunctionInContext(GLFWwindow* window)
{
	glfwSetKeyCallback(window,key_callback);
	glfwSetKeyCallback(window,transfromColor);
	glfwSetKeyCallback(window,key_callback_updataCamara);
	glfwSetCursorPosCallback(window,mouse_callback);
	glfwSetScrollCallback(window,scroll_callback);
	glfwSetMouseButtonCallback(window,mouse_callback1);
}

void key_callback_updataCamara(GLFWwindow* window, int key, int scancode, int action, int mode)
{

	if (action==GLFW_PRESS)
	{
		keys[key]=true;
	}
	else if (action==GLFW_RELEASE)
	{
		keys[key]=false;
	}
	do_movement();
}

void do_movement()
{
	cameraPos=Camera::GetInstance()->m_cameraPos;
	cameraFront=Camera::GetInstance()->m_cameraFront;
	cameraUp=Camera::GetInstance()->m_cameraUp;
	GLfloat camaraSpeed=DeltaTime;
	if (keys[GLFW_KEY_W])
	{
		cout<<"we have press "<<"W"<<endl;
		cameraPos+=camaraSpeed*cameraFront;
		
	}
	if (keys[GLFW_KEY_S])
	{
		cout<<"we have press "<<"S"<<endl;
		cameraPos-=camaraSpeed*cameraFront;
		
	}
	if (keys[GLFW_KEY_A])
	{
		cout<<"we have press "<<"A"<<endl;
		cameraPos+=glm::normalize(glm::cross(cameraFront,cameraUp))*camaraSpeed;
	
	}
	if (keys[GLFW_KEY_D])
	{
		cout<<"we have press "<<"D"<<endl;
		cameraPos-=glm::normalize(glm::cross(cameraFront,cameraUp))*camaraSpeed;
		
	}
	if (keys[GLFW_KEY_Q])
	{
		cout<<"we have press "<<"Q"<<endl;
		zoomin();
		
	}
	if (keys[GLFW_KEY_E])
	{
		cout<<"we have press "<<"E"<<endl;
		zoomout();
		
	}
	if (keys[GLFW_KEY_Z])
	{
		cout<<"we have press "<<"Z"<<endl;
		scaleToMin();
	}
	if (keys[GLFW_KEY_X])
	{
		cout<<"we have press "<<"X"<<endl;
		scaleToMax();
	}
//	cout<<"do_movement----->"<<"cameraPos.x=  "<<Camera::GetInstance()->m_cameraPos.x<<"  "<<"cameraPos.y=  "
//		<<Camera::GetInstance()->m_cameraPos.y<<"  "<<"cameraPos.z=   "<<Camera::GetInstance()->m_cameraPos.z<<endl;	
	if (keys[GLFW_KEY_C])
	{
		rotateZ_clockwise();
		Camera::GetInstance()->SetRotateMatrix(rotateAngle,vector3(0,0,1.0));
	}
	if (keys[GLFW_KEY_V])
	{

		 rotateZ_anticlockwise();
		 Camera::GetInstance()->SetRotateMatrix(rotateAngle,vector3(0,0,1.0));
	}
	translate_step();
	Camera::GetInstance()->m_cameraPos=cameraPos;
	Camera::GetInstance()->m_cameraFront=cameraFront;
	Camera::GetInstance()->m_cameraUp=cameraUp;
	Camera::GetInstance()->SetLookAt();
}

bool firstmoouse=true;
GLfloat yaw=-90.0f;
GLfloat pitch=0.0f;
GLfloat lastX=0,lastY=0;

void mouse_callback(GLFWwindow *window,double xpos,double ypos)
{
//	if (keys[GLFW_MOUSE_BUTTON_LEFT])
	{
		if (firstmoouse)
		{
			lastX=WIDTH/2;
			lastY=WIDTH/2;
			firstmoouse=false;
		}
		GLfloat xoffset=xpos-lastX;
		GLfloat yoffset=ypos-lastY;
		lastX=xpos;
		lastY=ypos;

		GLfloat sensitivity=0.05f;
		xoffset*=sensitivity;
		yoffset*=sensitivity;

		yaw-=xoffset;
		pitch+=yoffset;

		if (pitch>89.0f) 
		{
			pitch=89.0f;
		}
		if (pitch<=-89.0f)
		{
			pitch=-89.0f;
		}
		glm::vec3 front;
		front.x=cos(glm::radians(yaw))*cos(glm::radians(pitch));
		front.y=sin(glm::radians(pitch));
		front.z=sin(glm::radians(yaw))*cos(glm::radians(pitch));
	//	cameraFront=glm::normalize(front);
		Camera::GetInstance()->m_cameraFront=glm::normalize(front);
		Camera::GetInstance()->SetLookAt();

	}
		

}

void mouse_callback1(GLFWwindow*window,int action,int key,int mode)
{
		
	if (key==GLFW_MOUSE_BUTTON_LEFT)
	{
		cout<<"we have click LEFT mouse button"<<endl;
	//	glfwSetScrollCallback(window,scroll_callback);
		Camera::GetInstance()->m_fov=75;
		
	}
	if (key==GLFW_MOUSE_BUTTON_MIDDLE)
	{
		cout<<"we have click MIDDLE mouse button"<<endl;
		//	glfwSetScrollCallback(window,scroll_callback);
	}
	if (key==GLFW_MOUSE_BUTTON_RIGHT)
	{
		cout<<"we have click RIGHT mouse button"<<endl;
		//	glfwSetScrollCallback(window,scroll_callback);
	}
}

void scroll_callback(GLFWwindow*window,double xoffset,double yoffset)
{	
	float tempfov=Camera::GetInstance()->m_fov;
	if (tempfov>=44.0f&&tempfov<=50.0f)
	{
		tempfov-=yoffset*0.05;
	}
	if (tempfov<44)
	{
		tempfov=44;
	}
	if (tempfov>50)
	{
		tempfov=50;
	}
	Camera::GetInstance()->m_fov=tempfov;
	Camera::GetInstance()->SetProjection();
	cout<<yoffset<<"  "<<Camera::GetInstance()->m_fov<<endl;
}
void zoomin()
{
	float tempfov=Camera::GetInstance()->m_fov;
	if (tempfov>=44.0f&&tempfov<=50.0f)
	{
		tempfov-=0.05;
	}
	if (tempfov<44)
	{
		tempfov=44;
	}
	if (tempfov>50)
	{
		tempfov=50;
	}
	Camera::GetInstance()->m_fov=tempfov;
	Camera::GetInstance()->SetProjection();

}
void zoomout()
{
	float tempfov=Camera::GetInstance()->m_fov;
	if (tempfov>=44.0f&&tempfov<=50.0f)
	{
		tempfov+=0.05;
	}
	if (tempfov<44)
	{
		tempfov=44;
	}
	if (tempfov>50)
	{
		tempfov=50;
	}
	Camera::GetInstance()->m_fov=tempfov;
	Camera::GetInstance()->SetProjection();

}
void scaleToMin()
{

	if (zoomscale>=0.035)
	{
		zoomscale-=0.005;
		Camera::GetInstance()->SetScaleMatrix(vector3(1-zoomscale,1-zoomscale,1-zoomscale));
	}
	else
	{
		zoomscale=zoomscale;
		Camera::GetInstance()->SetScaleMatrix(vector3(1,1,1));
	}
	
	cout<<zoomscale<<endl;

	
}
void scaleToMax()
{
	if (zoomscale>=0.15)
	{
		zoomscale=zoomscale;
		Camera::GetInstance()->SetScaleMatrix(vector3(1,1,1));
	}
	else
	{

		zoomscale+=0.005;	
		Camera::GetInstance()->SetScaleMatrix(vector3(1+zoomscale,1+zoomscale,1+zoomscale));
	}	

	cout<<zoomscale<<endl;		
}


void rotateZ_clockwise()
{
	rotateAngle+=0.05;
	/*if (rotateAngle==360)
	{
	rotateAngle=0;
	}*/
	cout<<rotateAngle<<endl;
}
void rotateZ_anticlockwise()
{
	rotateAngle-=0.05;
	/*if (rotateAngle==-360)
	{
	rotateAngle=0;
	}*/
	cout<<rotateAngle<<endl;
}


void translate_step()
{
	if (keys[GLFW_KEY_LEFT])
	{
		if (step_x>=0)
		{
			Camera::GetInstance()->m_stepZ=0;
			Camera::GetInstance()->m_stepY=0;
			Camera::GetInstance()->m_stepX=-stepLength;
		}			
	}
	if (keys[GLFW_KEY_RIGHT])
	{
		if (step_x<=1.0)
		{
			Camera::GetInstance()->m_stepZ=0;
			Camera::GetInstance()->m_stepY=0;
			Camera::GetInstance()->m_stepX=stepLength;
		}
	}
	if (keys[GLFW_KEY_UP])
	{
		if (step_y<=1)
		{
			Camera::GetInstance()->m_stepZ=0;
			Camera::GetInstance()->m_stepX=0;
			Camera::GetInstance()->m_stepY=stepLength;
		}	
	}
	if (keys[GLFW_KEY_DOWN])
	{
		if (step_y>=0)
		{
			Camera::GetInstance()->m_stepZ=0;
			Camera::GetInstance()->m_stepX=0;	
			Camera::GetInstance()->m_stepY=-stepLength;
		}		
	}
	if (keys[GLFW_KEY_PAGE_UP])
	{
		if (step_y>=0)
		{
			Camera::GetInstance()->m_stepY=0;
			Camera::GetInstance()->m_stepX=0;
			Camera::GetInstance()->m_stepZ=stepLength;
		}		
	}
	if (keys[GLFW_KEY_PAGE_DOWN])
	{
		if (step_y>=0)
		{
			Camera::GetInstance()->m_stepY=0;
			Camera::GetInstance()->m_stepX=0;
			Camera::GetInstance()->m_stepZ=-stepLength;
		}		
	}
	Camera::GetInstance()->SetTranslateMatrix();
}
