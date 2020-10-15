#pragma once
#include "Object.h"
#include "IUpdate.h"

class NonRenderableObject :public Object ,public IUpdate
{
	virtual void shutDown() override;
	virtual void update() override;
};

