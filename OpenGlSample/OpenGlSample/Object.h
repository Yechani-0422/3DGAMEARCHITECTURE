#pragma once

#include "ICleanUp.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"
#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 

class Object :public ICleanUp
{
public:
	virtual ~Object() {};
};