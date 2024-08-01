#include "Moniter.h"

Moniter::Moniter()
{
}

Moniter::Moniter(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;

	this->width = width;
	this->height = height;

	areaOR(x, y, x + width, y + height);
}

Moniter::~Moniter()
{
}
