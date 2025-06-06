
#pragma once

//====================================================================================================

#include <iostream>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <graphics.h>
#include <conio.h>
#include <chrono>
#include <fstream>

//====================================================================================================
struct Vector
{
	double mod = 0.0;
	double angle = 0.0;
};

struct ObjectData
{
	double mass = 60.0;
	int mainColor = 0x0000aa;

	double x = 150.0;
	double y = 150.0;
	Vector v = { 0.0, 0.0 };
	Vector a = { 0.0, 0.0 };
};

struct PictureData
{
	int num = 0;
	std::string id = "id = null";
	std::string path = "path = null";

	int width = 0;
	int height = 0;
};

struct BaseMessageBox
{
	bool w = false;
	bool s = false;
	bool a = false;
	bool d = false;

	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;

	bool q = false;
	bool e = false;
	bool r = false;
	bool f = false;

	bool space = false;
	bool shift = false;
	bool esc = false;
	bool enter = false;

	int mx = 0;
	int my = 0;
	bool mouseLeft = false;
	bool mouseRight = false;
	bool mouseMiddle = false;
	bool mouseMove = false;
	int mouseWheel = 0;
};

extern const double PI;//圆周率
extern const double G;//万有引力常数

//====================================================================================================

std::array<double, 2> addXY(std::array<double, 2> xy1, std::array<double, 2> xy2);//相加
std::array<double, 2> subXY(std::array<double, 2> xy1, std::array<double, 2> xy2);//相减
std::array<double, 2> subXY(std::array<double, 2> xy);//取反
std::array<double, 2> multiplyXY(std::array<double, 2> xy1, std::array<double, 2> xy2);//数乘
std::array<double, 2> multiplyXY(std::array<double, 2> xy, double n);//数乘

double getDistance(std::array<double, 2> dxy);
double getDistance(std::array<double, 2> p1, std::array<double, 2> p2);//获取两个点的距离

double getAngle(std::array<double, 2> dxy);
double getAngle(std::array<double, 2> xy1, std::array<double, 2> xy2);//获取两个点的角度
double getAngle(Vector v1, Vector v2);

Vector getVector(std::array<double, 2> dxy);
Vector getVector(double dx, double dy);
Vector getVector(std::array<double, 2> p1, std::array<double, 2> p2);
std::array<double, 2> decVector(Vector v, double theta);//向量分解
std::array<double, 2> decVector(Vector v);//向量分解
Vector getUnitVector(Vector v);//获取单位向量
Vector getUnitVector(double dx, double dy);
Vector getUnitVector(std::array<double, 2> dxy);//获取单位向量
Vector getUnitVector(std::array<double, 2> p1, std::array<double, 2> p2);//获取单位向量
Vector addVector(Vector v1, Vector v2);//向量相加
Vector subVector(Vector v1, Vector v2);//向量相减
Vector subVector(Vector v);//向量取反
Vector multiplyVector(Vector v1, Vector v2);//向量数乘
Vector multiplyVector(Vector v, double n);//向量数乘

Vector getFrictionalForce(Vector v, double fri);//计算摩擦力
double getResistanceForce(double v, double s, double kuz);//计算阻力
Vector getResistanceForce(Vector v, double s, double kuz);//计算阻力

std::array<double, 2> elasticCollision(double m1, double m2, double v1, double v2);//计算弹性碰撞
std::array<Vector, 2> elasticCollision(double m1, double m2, Vector v1, Vector  v2);

double getVolumeOfBall(double r);//计算球体体积
double getRadiusOfBall(double v);//计算球体半径

double getGravitation(double m1, double m2, double d);//计算万有引力
Vector getGravitation(double m1, double m2, std::array<double, 2> p1, std::array<double, 2> p2);

//====================================================================================================

void getMessageBox(BaseMessageBox& mbox, ExMessage msg);//获取消息盒子
