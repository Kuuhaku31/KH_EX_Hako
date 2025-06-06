
#pragma once

#include "Camera.h"

class Cameraman : public Camera
{
public:
	double r = 100.0;

	Cameraman();
	Cameraman(double x, double y);
	~Cameraman();

	void cameraFollow(double tx, double ty, int mx, int my);
};

