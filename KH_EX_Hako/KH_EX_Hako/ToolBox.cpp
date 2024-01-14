
#include "ToolBox.h"

const double PI = 3.1415926535897932384626433832795;
const double G = 6.67408 * pow(10, -11);

//====================================================================================================================================

std::array<double, 2> addXY(std::array<double, 2> xy1, std::array<double, 2> xy2)
{
	return { xy1[0] + xy2[0], xy1[1] + xy2[1] };
}

std::array<double, 2> subXY(std::array<double, 2> xy1, std::array<double, 2> xy2)
{
	return addXY(subXY(xy1), xy2);
}

std::array<double, 2> subXY(std::array<double, 2> xy)
{
	return { -xy[0], -xy[1] };
}

std::array<double, 2> multiplyXY(std::array<double, 2> xy1, std::array<double, 2> xy2)
{
	return { xy1[0] * xy2[0], xy1[1] * xy2[1] };
}

std::array<double, 2> multiplyXY(std::array<double, 2> xy, double n)
{
	return multiplyXY(xy, { n, n });
}

double getDistance(std::array<double, 2> dxy)
{
	return sqrt(pow(dxy[0], 2) + pow(dxy[1], 2));
}

double getDistance(std::array<double, 2> p1, std::array<double, 2> p2)
{
	return getDistance(subXY(p1, p2));
}

double getAngle(std::array<double, 2> dxy)
{
	return atan2(dxy[1], dxy[0]);
}

double getAngle(std::array<double, 2> xy1, std::array<double, 2> xy2)
{
	return getAngle(subXY(xy1, xy2));
}

double getAngle(Vector v1, Vector v2)
{
	return v2.angle - v1.angle;
}

Vector getVector(std::array<double, 2> dxy)
{
	return { getDistance(dxy), getAngle(dxy) };
}

Vector getVector(double dx, double dy)
{
	return getVector({ dx, dy });
}

Vector getVector(std::array<double, 2> p1, std::array<double, 2> p2)
{
	return getVector(subXY(p1, p2));
}

std::array<double, 2> decVector(Vector v, double theta)
{
	double angle = v.angle - theta;
	return { v.mod * cos(angle), v.mod * sin(angle) };
}

std::array<double, 2> decVector(Vector v)//converts vector to x and y components
{
	return decVector(v, 0.0);
}

Vector getUnitVector(Vector v)
{
	if (v.mod == 0) { return { 0.0, v.angle }; }
	return { 1, v.angle };
}

Vector getUnitVector(double dx, double dy)
{
	return getUnitVector(getVector(dx, dy));
}

Vector getUnitVector(std::array<double, 2> dxy)
{
	return getUnitVector(getVector(dxy));
}

Vector getUnitVector(std::array<double, 2> p1, std::array<double, 2> p2)
{
	return getUnitVector(getVector(subXY(p1, p2)));
}

Vector addVector(Vector v1, Vector v2)
{
	return getVector(addXY(decVector(v1), decVector(v2)));
}

Vector subVector(Vector v1, Vector v2)
{
	return addVector(subVector(v1), v2);
}

Vector subVector(Vector v)
{
	return getVector(subXY(decVector(v)));
}

Vector multiplyVector(Vector v1, Vector v2)
{
	return getVector(multiplyXY(decVector(v1), decVector(v2)));
}

Vector multiplyVector(Vector v, double n)
{
	return getVector(multiplyXY(decVector(v), { n, n }));
}

Vector getFrictionalForce(Vector v, double fri)
{
	return multiplyVector(subVector(getUnitVector(v)), fri);
}

double getResistanceForce(double v, double s, double kuz)
{
	return pow(v, 2) * s * kuz;
}

Vector getResistanceForce(Vector v, double s, double kuz)
{
	return multiplyVector(subVector(getUnitVector(v)), getResistanceForce(v.mod, s, kuz));
}


double getVolumeOfBall(double r)
{
	return 4.0 / 3.0 * PI * pow(r, 3);
}

double getRadiusOfBall(double v)
{
	return pow(3.0 / 4.0 * v / PI, 1.0 / 3.0);
}

std::array<double, 2> elasticCollision(double m1, double m2, double v1, double v2)
{
	return { (m1 - m2) / (m1 + m2) * v1 + 2 * m2 / (m1 + m2) * v2, 2 * m1 / (m1 + m2) * v1 + (m2 - m1) / (m1 + m2) * v2 };
}

std::array<Vector, 2> elasticCollision(double m1, double m2, Vector v1, Vector v2)
{
	std::cout << "还没做好" << std::endl;
	return { v1, v2 };
}

double getGravitation(double m1, double m2, double d)
{
	return G * m1 * m2 / pow(d, 2);
}

Vector getGravitation(double m1, double m2, std::array<double, 2> p1, std::array<double, 2> p2)
{
	return { getGravitation(m1, m2, getDistance(p1, p2)), getAngle(p1, p2) };
}

void getMessageBox(BaseMessageBox& mbox, ExMessage msg)
{
    
    if (msg.message == WM_KEYDOWN) switch (msg.vkcode)
    {
    case 0x57:      mbox.w      = true; break;
    case 0x53:      mbox.s      = true; break;
    case 0x41:      mbox.a      = true; break;
    case 0x44:      mbox.d      = true; break;
    case VK_UP:     mbox.up     = true; break;
    case VK_DOWN:   mbox.down   = true; break;
    case VK_LEFT:   mbox.left   = true; break;
    case VK_RIGHT:  mbox.right  = true; break;
    case 0x51:      mbox.q      = true; break;
    case 0x45:      mbox.e      = true; break;
    case 0x52:      mbox.r      = true; break;
    case 0x46:      mbox.f      = true; break;
    case VK_SPACE:  mbox.space  = true; break;
    case VK_SHIFT:  mbox.shift  = true; break;
    case VK_ESCAPE: mbox.esc    = true; break;
    case VK_RETURN: mbox.enter  = true; break;
    }
    if (msg.message == WM_KEYUP) switch (msg.vkcode)
    {
    case 0x57:      mbox.w      = false; break;
    case 0x53:      mbox.s      = false; break;
    case 0x41:      mbox.a      = false; break;
    case 0x44:      mbox.d      = false; break;
    case VK_UP:     mbox.up     = false; break;
    case VK_DOWN:   mbox.down   = false; break;
    case VK_LEFT:   mbox.left   = false; break;
    case VK_RIGHT:  mbox.right  = false; break;
    case 0x51:      mbox.q      = false; break;
    case 0x45:      mbox.e      = false; break;
    case 0x52:      mbox.r      = false; break;
    case 0x46:      mbox.f      = false; break;
    case VK_SPACE:  mbox.space  = false; break;
    case VK_SHIFT:  mbox.shift  = false; break;
    case VK_ESCAPE: mbox.esc    = false; break;
    case VK_RETURN: mbox.enter  = false; break;
    }
    if (msg.message == WM_MOUSEMOVE)
    {
        mbox.mx = msg.x;
        mbox.my = msg.y;
        mbox.mouseMove = true;
    }
    mbox.mouseLeft = msg.lbutton;
    mbox.mouseRight = msg.rbutton;
    mbox.mouseMiddle = msg.mbutton;
    mbox.mouseWheel = msg.wheel;
}
