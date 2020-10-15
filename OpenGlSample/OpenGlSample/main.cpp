#include "FileManager.h"
#include "Object.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Sphere.h"
#include "Obj.h"

int main(void)
{
	Renderer::GetInstance()->init();

	Obj* cube = new Obj();
	Obj* human = new Obj();
	NonRenderableObject* non = new NonRenderableObject();

	RenderableObject* sphere = new Sphere();
	
	FileManager::GetInstance()->loadingObj(cube, "cube.obj", "suntexture.DDS", "20151687_vs.shader", "20151687_fs.shader");
	FileManager::GetInstance()->loadingObj(human, "suzanne.obj", "uvtemplate.DDS", "20151687_vs.shader", "20151687_fs.shader");
	
	Renderer::GetInstance()->addObject(cube);
	Renderer::GetInstance()->addObject(human);
	Renderer::GetInstance()->addObject(sphere);

	cube->setPos(0, 0, 0);	
	human->setPos(2, 0, 3);
	sphere->setPos(2, 0, -4);

	
	Renderer::GetInstance()->setCameraPos(2, 0, 0);	

	while (true)
	{
		Renderer::GetInstance()->renderUp();

		Renderer::GetInstance()->update(non);
		Renderer::GetInstance()->render();
		

		Renderer::GetInstance()->renderDown();
	}	
	

	cube->shutDown();
	human->shutDown();
	sphere->shutDown();
	Renderer::GetInstance()->shutDown();

	delete non;

	delete cube;
	delete human;
	delete sphere;

	return 0;
}