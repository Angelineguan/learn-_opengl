#pragma  once
#include <GL/glm/glm.hpp>
#include <GL/glm/gtc/matrix_transform.hpp>
#include <GL/glm/gtc/type_ptr.hpp>

#define vector3 glm::vec3
#define  matrix4 glm::mat4
  GLfloat WIDTH, HEIGHT;
class Camera
{
public:
		
	static Camera* GetInstance()
	{
		if (Instance==NULL)
		{
			Instance=new Camera();
			Instance->InitialCamera();
		}
		else
		{
			return Instance;
		}
	}
	static Camera* CreatInstance()
	{
		Instance=new Camera();
		Instance->InitialCamera();
		return Instance;
	
	}
	void InitialCamera()
	{
		m_cameraPos=vector3(0.0,0.0,1.0);
		m_cameraFront=vector3(0.0,0.0,-1.0);
		m_cameraUp=vector3(0.0,1.0,0.0);
		
		m_scaleMatrix=glm::scale(m_scaleMatrix,vector3(0.1,0.1,0.1));
		m_fov=45.0f;
		m_stepX=0;
		m_stepY=0;
		m_stepZ=0;
		SetLookAt();
		SetProjection();
	}
	void SetLookAt()
	{	
		m_view=glm::lookAt(m_cameraPos,m_cameraFront,m_cameraUp);		
	}
	matrix4 getLookAt()
	{
		return m_view;
	}
	void SetProjection()
	{
		m_projection=glm::perspective(m_fov, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
	}
	matrix4 GetPersPective()
	{
		return m_projection;
	}
	float getFov()
	{
		return m_fov;
	}
	void SetTranslateMatrix()
	{
		m_translateMatrix=glm::translate(m_translateMatrix,vector3(m_stepX,m_stepY,m_stepZ));
	}
	matrix4 GetTranslateMatrix()
	{
		return m_translateMatrix;
	}
	void SetScaleMatrix(glm::vec3 scale)
	{
	//	m_scaleMatrix=glm::scale(m_scaleMatrix,vector3(0.1,0.1,0.1));
		m_scaleMatrix=glm::scale(m_scaleMatrix,scale);
	}
	matrix4 GetScaleMatrix()
	{
		return m_scaleMatrix;
	}
	void SetRotateMatrix(GLfloat angle,glm::vec3 axis)
	{
		m_rotateMatrix=glm::rotate(m_rotateMatrix,angle,axis);
	}
	matrix4 GetRotateMatrix()
	{
		return m_rotateMatrix;
	}

	vector3 m_cameraPos;
	vector3 m_cameraFront;
	vector3 m_cameraUp;

	float m_pitch;
	float m_yaw;
	float m_roll;

	float m_fov;
	matrix4 m_view;
	matrix4 m_projection;

	matrix4 m_rotateMatrix;
	matrix4 m_scaleMatrix;
	matrix4 m_translateMatrix;
	float m_stepX;
	float m_stepY;
	float m_stepZ;
 	

private:
	static Camera* Instance;
	Camera(){}	
	Camera(const Camera&a){}
	Camera&operator=(const Camera&a){}
};
Camera* Camera::Instance=Camera::CreatInstance();
