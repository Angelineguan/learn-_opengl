#pragma  once
#include "ShaderManager.h"
#include "Vector3.h"
#include "util.h"




class Triangle
{
	
public:
	Triangle(DrawContext*_drawContext,GLfloat*_vertex,size_t num);
	~Triangle();
	void draw(bool isDrawOutLine);
	void setInnerColor(Color color);
	void setOutLineColor(Color color);
	void setOffset(Vector3* offset);
	void setOutLineFlag(bool isDraw);
private:
	GLuint m_vboHandle;
	GLuint m_vaoHandle;
	ShaderProgram* m_programe;
	DrawContext*m_drawContext;
	Color m_innerColor;
	Color m_outLineColor;
	Vector3 m_offset;
	Vector3 m_scale;
};


