
#include "Guides.h"

Guides::Guides()
{
}

Guides::~Guides()
{
}

void Guides::renewGuides(double x, double y, double mx, double my)
{
	this->x = x;
	this->y = y;
	followMouse(mx, my);
}

void Guides::followMouse(double mx, double my)
{
	std::array<double, 2> dxy = { mx, my };
	angle = getAngle(dxy);
}

void Guides::drawGuides()
{
	setlinecolor(GREEN);
	setlinestyle(PS_SOLID, 1);
	line(x, y, x + 50 * cos(angle), y + 50 * sin(angle));
}
