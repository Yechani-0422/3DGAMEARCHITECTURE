#include "Renderer.h"
#include "Time.h"

#include "Mario.h"
#include "Bg.h"

#include "testNonRenderObj.h"

#include "CompositeObj.h"


int main(void)
{
	Mario* mario = new Mario();
	Mario* mario2 = new Mario();
	Bg* bg = new Bg();
	testNonRenderObj* testNonRender = new testNonRenderObj();

	Renderer::GetInstance()->init();
	
	mario->add(mario2);
	mario->setScale(0.5f, 0.5f, 0.5f);
	mario->setRot(1, 0, 0, 1);
	mario2->setPos(5, 0, 0);
	mario2->setRot(1, 0, 0, 1);
	mario2->setScale(0.5f, 0.5f, 0.5f);

	mario->add(bg);

	while (glfwGetKey(Renderer::GetInstance()->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(Renderer::GetInstance()->window) == 0)
	{
		Renderer::GetInstance()->renderUp();
		
		if (Time::GetInstance()->IsFixedRendering())
		{
			Renderer::GetInstance()->update();
		}		

		Renderer::GetInstance()->render();		

		Renderer::GetInstance()->renderDown();		
	}	
	

	Renderer::GetInstance()->shutDown();

	delete mario;
	delete mario2;
	delete bg;
	delete testNonRender;

	return 0;
}


