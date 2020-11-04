#include "Renderer.h"
#include "Time.h"

#include "Mario.h"
#include "Bg.h"

#include "testNonRenderObj.h"



int main(void)
{
	Mario* mario = new Mario();
	Bg* bg = new Bg();
	testNonRenderObj* testNonRender = new testNonRenderObj();

	Renderer::GetInstance()->init();

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
	delete bg;
	delete testNonRender;

	return 0;
}


