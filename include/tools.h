
#pragma once

#include "ToolBox.h"

#include "Library.h"

//====================================================================================================================================

struct BlockData
{
	ObjectData OD;

	int lineColor = 0xaa0000;
	double width = 20.0;
	double height = 20.0;
	std::array<double, 2> p1 = { 0.0, 0.0 };
	std::array<double, 2> p2 = { 0.0, 0.0 };
	std::array<double, 2> p3 = { 0.0, 0.0 };
	std::array<double, 2> p4 = { 0.0, 0.0 };
};

//====================================================================================================================================

extern const std::array<int, 2> WINDOW_SIZE;
extern const std::array<int, 2> WORLD_SIZE;//世界大小
extern const std::array<int, 2> SIGHT_SIZE;//视野大小

extern const double KUZ_0;//空气阻力系数
extern const double KUZ_1;//水阻力系数
extern const double KUZ_2;//沙阻力系数

extern const double FRI_0;//石头摩擦系数
extern const double FRI_1;//木头摩擦系数
extern const double FRI_2;//金属摩擦系数

extern const double FRICTIONAL_FORCE_0;//石头摩擦力
extern const double FRICTIONAL_FORCE_1;//木头摩擦力
extern const double FRICTIONAL_FORCE_2;//金属摩擦力

extern const double GRAVITATION_0;//地球引力
extern const double GRAVITATION_1;//月球引力
extern const double GRAVITATION_2;//太阳引力

extern const double FORCE_0;
extern const double FORCE_1;
extern const double FORCE_2;

extern const int TIMER_0;//计时器0
extern const int TIMER_1;//计时器1
extern const int TIMER_2;//计时器2

extern const int BACKGROUND_COLOR;//背景颜色

extern const int COLOR_0;
extern const int COLOR_1;
extern const int COLOR_2;
extern const int COLOR_3;
extern const int COLOR_4;
extern const int COLOR_5;

extern const int WALL_COLOR;// = 0x2d2590;
extern const int WALL_DATACOLOR;// = 0x000000;
extern const int MAINMAP_DATACOLOR;// = 0xffffff;

extern const int IKACYANN_COLOR;// = 0x00a8f3;

//====================================================================================================================================

Vector control(BaseMessageBox mbox);

void setText(char arr[], int color);