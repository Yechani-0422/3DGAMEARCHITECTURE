#pragma once

#include "FileManager.h"
#include "ICleanUp.h"

class RenderableObject;

class Renderer:public ICleanUp
{
private:
	glm::vec3 cameraPos;	

	static Renderer* instance;
public:
	

	static Renderer* GetInstance()
	{
		if (instance == 0)
		{
			instance = new Renderer();
		}

		return instance;
	};

	void render(RenderableObject* obj);
	void setCameraPos(float x, float y, float z);
	int init();
	virtual void shutDown() override;

	void renderUp();
	void renderDown();

	GLFWwindow* window;
	
	
};

