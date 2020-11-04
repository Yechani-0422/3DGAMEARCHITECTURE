#include "RenderableObject.h"
#include "Renderer.h"



RenderableObject::RenderableObject()
{
	_IsMoveCheck = false;
	Renderer::GetInstance()->addRenderObject(this);
}