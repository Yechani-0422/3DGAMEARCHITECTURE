#pragma once
#include "RenderableObject.h"
#include "IUpdate.h"

class Obj:public RenderableObject,public IUpdate
{
public:
	virtual void shutDown() override;
	virtual void setPos(float x, float y, float z) override;	
	virtual void update() override;
};

