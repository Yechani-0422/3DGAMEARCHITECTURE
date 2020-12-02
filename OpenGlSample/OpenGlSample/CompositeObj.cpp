#include "CompositeObj.h"
#include <iostream>

CompositeObj::CompositeObj()
{
	_Table = new vector<Object*>();
	CompositRot = glm::mat4(1.0f);
	ComPositPos = glm::mat4(1.0f);
	ComPositScale = glm::mat4(1.0f);
}

CompositeObj::~CompositeObj()
{
	for (
		vector<Object*>::const_iterator it = _Table->begin();
		it != _Table->end();
		++it
		)
	{
		delete (*it);
	}

	_Table->clear();

	delete _Table;
}


void CompositeObj::add(Object* addObj)
{
	_Table->push_back(addObj);
}

void CompositeObj::RotMatrix(glm::mat4 _rot) 
{
	CompositRot = _rot;
}

void CompositeObj::PosMatrix(glm::mat4 _pos)
{
	ComPositPos = _pos;
}

void CompositeObj::ScaleMatrix(glm::mat4 _scale)
{
	ComPositScale = _scale;
}