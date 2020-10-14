#pragma once

#include "graphicLib.h"


using namespace std;

class renderObject
{
public:
	renderObject(string str, string str1 ,const char * str2, const char * str3);
	~renderObject();

	void render();
};

