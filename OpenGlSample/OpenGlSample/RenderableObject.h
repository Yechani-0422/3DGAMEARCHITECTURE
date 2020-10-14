#pragma once
#include "Object.h"
#include <vector>

class RenderableObject :public Object
{
public:
	virtual void shutDown() override {};
	virtual void setPos(float x, float y, float z) {};

	glm::vec3 objPos;
	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint Texture;
	GLuint textureID;
	GLuint MatrixID;
	GLuint programID;
	GLuint VertexArrayID;
};

