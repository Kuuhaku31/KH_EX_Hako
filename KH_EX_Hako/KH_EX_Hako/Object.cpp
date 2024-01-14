
#include "Object.h"

Object::Object()
{
}

Object::Object(ObjectData OD) : mass(OD.mass), mainColor(OD.mainColor), x(OD.x), y(OD.y), v(OD.v), a(OD.a)
{
}

Object::~Object()
{
}

void Object::moveObject(Vector f)
{
	a = addVector(a, multiplyVector(f, 1 / mass));
}

void Object::renewObject()
{
	v = addVector(v, a);
	if (v.mod < 1.0) { v = multiplyVector(v, 0); }

	a = multiplyVector(a, 0);

	double dx = decVector(v)[0] * 0.1;
	double dy = decVector(v)[1] * 0.1;

	x += dx;
	y += dy;
}

void Object::drawObject()
{
	double r = mass * 0.1;
	setfillcolor(mainColor);
	setlinecolor(mainColor / 2);
	fillcircle(x, y, r);
}

