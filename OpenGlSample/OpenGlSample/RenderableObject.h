#pragma once
#include "CompositeObj.h"
#include <vector>


class RenderableObject :public CompositeObj
{
private:
	//bool _IsMoveCheck;
public:
	RenderableObject();
	virtual void init() override {};
	virtual void render() override {};
	virtual void render() const {};
	virtual void update() override {};
	virtual void shutDown() override {};
	virtual void setPos(float x, float y, float z) {};
	virtual void setRot(float speed, float x, float y, float z) {};
	virtual void setScale(float x, float y, float z) {};
	virtual void setCameraPos(float x, float y, float z) {};

	virtual void add(Object* addObj)override {};
		
	float rotSpeed;
	glm::mat4 Scale;
	glm::vec3 scaleVec;
	glm::vec3 rotVec;
	glm::mat4 Rot;
	glm::vec3 position;
	glm::vec3 cameraPos;
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

