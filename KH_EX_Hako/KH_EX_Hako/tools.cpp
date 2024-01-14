
#include "tools.h"

//====================================================================================================================================

const std::array<int, 2> WINDOW_SIZE = { 1440, 810 };
const std::array<int, 2> WORLD_SIZE = { 2000, 2000 };
const std::array<int, 2> SIGHT_SIZE = { 1440, 810 };

const double KUZ_0 = 1.0;
const double KUZ_1 = 1.0 * pow(10, -4);
const double KUZ_2 = 5.0 * pow(10, -5);

const double FRI_0 = 1.0;
const double FRI_1 = 0.5;
const double FRI_2 = 0.1;

const double FRICTIONAL_FORCE_0 = 1.0;
const double FRICTIONAL_FORCE_1 = 5.0 * pow(10, 1);
const double FRICTIONAL_FORCE_2 = 5.0 * pow(10, 0);

const double GRAVITATION_0 = 1.0;
const double GRAVITATION_1 = 1.6 * pow(10, 2);
const double GRAVITATION_2 = 0.1;

const double FORCE_0 = 1.0;
const double FORCE_1 = 9.0 * pow(10, 1);
const double FORCE_2 = 1.0;

const int TIMER_0 = 0;
const int TIMER_1 = 0;
const int TIMER_2 = 0;

const int BACKGROUND_COLOR = 0xcccccc;

const int COLOR_0 = 0x000000;
const int COLOR_1 = 0x0000ff;
const int COLOR_2 = 0x00ff00;
const int COLOR_3 = 0x00ffff;
const int COLOR_4 = 0xff0000;
const int COLOR_5 = 0xff00ff;

const int WALL_COLOR = 0x777777;
const int WALL_DATACOLOR = 0x000000;
const int MAINMAP_DATACOLOR = 0xffffff;

const int IKACYANN_COLOR = 0x00a8f3;

//======================================================================================================================================

Vector control(BaseMessageBox mbox)
{
	double u[2] = { 0.0, 0.0 };

	if (mbox.up) { u[1] -= 1; }
	if (mbox.down) { u[1] += 1; }
	if (mbox.right) { u[0] += 1; }
	if (mbox.left) { u[0] -= 1; }

	return getVector(u[0], u[1]);
}

void setText(char arr[], int color)
{
    settextcolor(color);
    settextstyle(80, 0, "楷体");
    setbkmode(TRANSPARENT);
    int x1 = 0, y1 = 0, x2 = WINDOW_SIZE[0], y2 = WINDOW_SIZE[1];
    int width = textwidth(arr);
    int height = textheight(arr);
    int textx = (x2 - x1) / 2 - width / 2 + x1;
    int texty = (y2 - y1) / 2 - height / 2 + y1;
    outtextxy(textx, texty, arr);
}
