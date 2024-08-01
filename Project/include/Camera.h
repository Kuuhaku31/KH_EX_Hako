
#pragma once

#include "Object.h"

class Camera : public Object
{
public:
	int sight__width = 0;
	int sight_height = 0;
	IMAGE sight;

	int x1 = x - sight__width / 2;
	int y1 = y - sight_height / 2;
	int x2 = x + sight__width / 2;
	int y2 = y + sight_height / 2;

	Camera();
	Camera(double x, double y);
	Camera(int sight_width, int sight_height);
	Camera(double x, double y, int sight_width, int sight_height);
	~Camera();

	void controlCamera(BaseMessageBox mbox);
	void renewCamera();
	void see(IMAGE* img);
	void show();
};

