#pragma once

class Vector3
{
public:
	Vector3(){}
	Vector3(const Vector3 &a):m_x(a.m_x),m_y(a.m_y),m_z(a.m_z){}
	Vector3(float _x,float _y,float _z):m_x(_x),m_y(_y),m_z(_z){}
	Vector3 &operator =(const Vector3 &a)
	{
		m_x=a.m_x;
		m_y=a.m_x;
		m_z=a.m_z;
		return *this;
	}
	bool operator==(const Vector3 &a)const
	{
		return m_x==a.m_x&&m_y==a.m_y&&m_z==a.m_z;
	}
	bool operator!=(const Vector3 &a)const
	{
		return m_x!=a.m_x||m_y!=a.m_y||m_z!=a.m_z;
	}
	void setZero()
	{
		m_x=m_y=m_z=0;
	}
	Vector3 operator-()const
	{
		return Vector3(-m_x,-m_y,-m_z);
	}
	Vector3 operator+(const Vector3 &a)const
	{
		return Vector3(m_x+a.m_x,m_y+a.m_y,m_z+a.m_z);
	}
	Vector3 operator-(const Vector3 &a)const
	{
		return Vector3(m_x-a.m_x,m_y-a.m_y,m_z-a.m_z);
	}
	Vector3 operator*(float a)const
	{
		return Vector3(a*m_x,a*m_y,a*m_z);
	}
	Vector3 operator/(float a)const
	{
		float factor=1.0f/a;
		return Vector3(factor*m_x,factor*m_y,factor*m_z);
	}
	Vector3 operator +=(const Vector3 &a)  
	{
		m_x+=a.m_x;
		m_y+=a.m_y;
		m_z+=a.m_z;
		return *this;
	}
	Vector3 operator -=(const Vector3 &a)  
	{
		m_x-=a.m_x;
		m_y-=a.m_y;
		m_z-=a.m_z;
		return *this;
	}
	Vector3 operator *=(float a)  
	{
		m_x*=a;
		m_y*=a;
		m_z*=a;
		return *this;
	}
	Vector3 operator /=(float a)  
	{
		float factor=1.0f/a;
		m_x*=factor;
		m_y*=factor;
		m_z*=factor;
		return *this;
	}

	void normalize()
	{
		float lengthSquare=m_x*m_x+m_y*m_y+m_z*m_z;
		if (lengthSquare>0)
		{
			float factor=1.0f/sqrt(lengthSquare);
			m_x*=factor;
			m_y*=factor;
			m_z*=factor;
		}
	}

	float operator * (const Vector3 &a) const
	{
		return m_x*a.m_x+m_y*a.m_y+m_z*a.m_z;
	}

	inline float length()
	{
		return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
	}
	
	inline float distance(const Vector3 &left,const Vector3 &right)
	{
		float dx=left.m_x-right.m_x;
		float dy=left.m_y-right.m_y;
		float dz=left.m_z-right.m_z;
		return sqrt(dx*dx+dy*dy+dz*dz);
	}

	float m_x;
	float m_y;
	float m_z;
};


