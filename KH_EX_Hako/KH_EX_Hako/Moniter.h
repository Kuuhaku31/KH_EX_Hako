
#pragma once

#include "Area.h"

class Moniter : public Area
{
public:
	int x = 0;
	int y = 0;

	int width = 0;
	int height = 0;

	Moniter();
	Moniter(int x, int y, int width, int height);
	~Moniter();
};

