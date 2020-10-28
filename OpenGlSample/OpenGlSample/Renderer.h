#pragma once

#include "FileManager.h"
#include "ICleanUp.h"
#include "IUpdate.h"
#include <vector>

class RenderableObject;

class Renderer:public ICleanUp
{
private:
	glm::vec3 cameraPos;	

	static Renderer* instance;
	std::vector< RenderableObject*> objList;
	void renderObject(RenderableObject* obj);
public:
	static Renderer* GetInstance()
	{
		if (instance == 0)
		{
			instance = new Renderer();
		}

		return instance;
	};

	void addObject(RenderableObject* obj);
	void update(IUpdate* obj);
	void render();
	void setCameraPos(float x, float y, float z);
	int init();
	virtual void shutDown() override;

	void renderUp();
	void renderDown();

	GLFWwindow* window;
	
	
};

