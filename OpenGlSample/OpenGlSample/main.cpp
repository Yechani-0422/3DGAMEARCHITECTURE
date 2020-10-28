#include "FileManager.h"
#include "Object.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Sphere.h"
#include "Obj.h"
#include "Time.h"



int main(void)
{
	Renderer::GetInstance()->init();

	Obj* mario = new Obj();
	Obj* bg = new Obj();
	NonRenderableObject* non = new NonRenderableObject();

	RenderableObject* sphere = new Sphere();
	
	FileManager::GetInstance()->loadingObj(mario, "cube.obj", "character.DDS", "20151687_vs.shader", "20151687_fs.shader");
	FileManager::GetInstance()->loadingObj(bg, "bg.obj", "bgdds.DDS", "20151687_vs.shader", "20151687_fs.shader");
	
	Renderer::GetInstance()->addObject(mario);
	Renderer::GetInstance()->addObject(bg);
	Renderer::GetInstance()->addObject(sphere);

	mario->setPos(0, 0, -20);
	bg->setPos(0, 5, -51);
	sphere->setPos(200, 0, -4);

	mario->setMoving(true);

	
	Renderer::GetInstance()->setCameraPos(0, 0, 0);	

	while (glfwGetKey(Renderer::GetInstance()->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(Renderer::GetInstance()->window) == 0)
	{
		Renderer::GetInstance()->renderUp();
		
		if (Time::GetInstance()->IsFixedRendering())
		{
			Renderer::GetInstance()->update(non);
			Renderer::GetInstance()->update(mario);
		}		

		Renderer::GetInstance()->render();
		

		Renderer::GetInstance()->renderDown();		
	}	
	

	mario->shutDown();
	bg->shutDown();
	sphere->shutDown();
	Renderer::GetInstance()->shutDown();

	delete non;

	delete mario;
	delete bg;
	delete sphere;

	return 0;
}


