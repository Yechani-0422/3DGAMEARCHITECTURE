#pragma once
#include "RenderableObject.h"
class Sphere:public RenderableObject
{
public:
	Sphere();
	virtual void shutDown() override;
    virtual	void setPos(float x, float y, float z) override;
};

