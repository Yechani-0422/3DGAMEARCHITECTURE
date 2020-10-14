#pragma once
#include "RenderableObject.h"

class Obj:public RenderableObject
{
public:
	virtual void shutDown() override;
	virtual void setPos(float x, float y, float z) override;	
};

