#include "graphicLib.h"
#include "renderObject.h"

int main(void)
{
	graphicLib::GetInstance()->tearUp();

	renderObject* cube1 = new renderObject("vertex_data.csv", "color_data.csv", "20151687_vs.shader", "20151687_fs.shader");
	do {

		graphicLib::GetInstance()->RenderUp();
		cube1->render();
		graphicLib::GetInstance()->RenderDown();
	} while (glfwGetKey(graphicLib::GetInstance()->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(graphicLib::GetInstance()->window) == 0);
	graphicLib::GetInstance()->tearDown();

	return 0;
}