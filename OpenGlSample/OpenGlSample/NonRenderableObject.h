#pragma once
#include "Object.h"
class NonRenderableObject :public Object
{
	virtual void shutDown() override;
};

