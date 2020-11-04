#include "NonRenderableObject.h"
#include "Renderer.h"

NonRenderableObject::NonRenderableObject()
{
	Renderer::GetInstance()->addNonRenderObject(this);
}

void NonRenderableObject::init()
{

}

void NonRenderableObject::render()
{

}

void NonRenderableObject::update()
{

}

void NonRenderableObject::shutDown()
{

}
