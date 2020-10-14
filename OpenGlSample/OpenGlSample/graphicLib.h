#pragma once

#include <string>
#include <vector>
#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

using namespace std;

class graphicLib
{
public:
	
	int tearUp();
	void RenderUp();
	void RenderDown();
	void tearDown();
	vector<GLfloat> LoadCsv(string f_csv);
	GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);

	GLFWwindow* window;

	GLuint programID;
	GLuint VertexArrayID;
	GLuint vertexbuffer;

	static graphicLib* GetInstance()
	{
		if (instance == 0)
		{
			instance = new graphicLib();
		}

		return instance;
	};

	
private:
	graphicLib();
	~graphicLib();

	
	
	

	static graphicLib* instance;
};

