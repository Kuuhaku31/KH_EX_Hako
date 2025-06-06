#include "Cameraman.h"

Cameraman::Cameraman()
{
}

Cameraman::Cameraman(double x, double y) : Camera(x, y)
{
}

Cameraman::~Cameraman()
{
}

void Cameraman::cameraFollow(double tx, double ty, int mx, int my)
{
	double px = (tx + mx + x1) / 2;
	double py = (ty + my + y1) / 2;
	double d = getDistance({ px, py }, { x, y });
	if (d > r) { moveObject({ d / 10.0, getAngle({ px - x, py - y }) }); r = 100; }
	if (d <= r) { r = 120; }
	moveObject(getResistanceForce(v, 100.0, KUZ_2));
	moveObject(getFrictionalForce(v, FRICTIONAL_FORCE_2));
	renewCamera();
}
