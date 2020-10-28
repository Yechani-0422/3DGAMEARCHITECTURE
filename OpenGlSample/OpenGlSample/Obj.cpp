#include "Obj.h"


void Obj::setPos(float x, float y, float z)
{
	objPos = glm::vec3(x, y, z);
}


void Obj::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(MatrixID);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void Obj::update()
{

}