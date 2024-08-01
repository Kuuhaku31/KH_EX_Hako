
#include "Camera.h"

Camera::Camera()
{
	mass = 10.0;
	this->sight__width = 1440;
	this->sight_height = 810;
	getimage(&sight, 0, 0, 1440, 810);
	renewCamera();
}

Camera::Camera(double x, double y)
{
	mass = 10.0;
	this->x = x;
	this->y = y;
	this->sight__width = 1440;
	this->sight_height = 810;
	getimage(&sight, 0, 0, 1440, 810);
	renewCamera();
}

Camera::Camera(int sight_width, int sight_height)
{
	mass = 10.0;
	this->sight__width = sight_width;
	this->sight_height = sight_height;
	getimage(&sight, 0, 0, sight_width, sight_height);
	renewCamera();
}

Camera::Camera(double x, double y, int sight_width, int sight_height)
{
	mass = 10.0;
	this->x = x;
	this->y = y;
	this->sight__width = sight_width;
	this->sight_height = sight_height;
	getimage(&sight, 0, 0, sight_width, sight_height);
	renewCamera();
}

Camera::~Camera()
{
}

void Camera::controlCamera(BaseMessageBox mbox)
{
	Vector u = control(mbox);
	u.mod *= 10.0;
	moveObject(u);
}

void Camera::renewCamera()
{
	renewObject();
	x1 = x - sight__width / 2;
	y1 = y - sight_height / 2;
	x2 = x + sight__width / 2;
	y2 = y + sight_height / 2;
}

void Camera::see(IMAGE* img)
{
	SetWorkingImage(img);
	getimage(&sight, x1, y1, sight__width, sight_height);
	SetWorkingImage();
}

void Camera::show()
{
	SetWorkingImage();
	putimage(0, 0, &sight);
}

