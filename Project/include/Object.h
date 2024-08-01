
#pragma once

#include "tools.h"

class Object
{
public:
	double mass = 100.0;
	int mainColor = 0x000000;

	double x = 0.0;
	double y = 0.0;
	Vector v = { 0.0, 0.0 };
	Vector a = { 0.0, 0.0 };

	Object();
	Object(ObjectData OD);
	~Object();

	void moveObject(Vector f);
	void renewObject();

	void drawObject();
};

