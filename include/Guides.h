
#pragma once

#include "tools.h"

class Guides
{
public:
	double angle = 0.0;
	double x = 0.0;
	double y = 0.0;

	Guides();
	~Guides();

	void renewGuides(double x, double y, double mx, double my);
	void followMouse(double mx, double my);
	void drawGuides();
};

