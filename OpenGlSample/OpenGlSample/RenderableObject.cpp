#include "RenderableObject.h"

//
//void RenderableObject::setPos(float x, float y, float z)
//{
//	objPos = glm::vec3(x, y, z);
//}
//
//
//void RenderableObject::shutDown()
//{
//	glDeleteBuffers(1, &vertexbuffer);
//	glDeleteBuffers(1, &uvbuffer);
//	glDeleteBuffers(1, &normalbuffer);
//	glDeleteProgram(MatrixID);
//	glDeleteProgram(programID);
//	glDeleteVertexArrays(1, &VertexArrayID);
//}

RenderableObject::RenderableObject()
{
	_IsMoveCheck = false;
}

void RenderableObject::setMoving(bool IsCheck)
{
	_IsMoveCheck = IsCheck;
}

bool RenderableObject::getMoving()
{
	return _IsMoveCheck;
}