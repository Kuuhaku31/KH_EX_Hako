
#pragma once

#include "Block.h"

#include "Guides.h"

class BlockDriver : public Block
{
public:
    Guides* guides = nullptr;

    BaseMessageBox mbox;

    IMAGE skin_a;
    IMAGE skin_b;

    double energy = 10.0;
    int jumpTimer = 0;
    int jump2 = 0;

    std::array<double, 2> p1_1 = { p1[0] - 1, p1[1] };
    std::array<double, 2> p1_2 = { p1[0], p1[1] - 1 };
    std::array<double, 2> p2_1 = { p2[0], p2[1] - 1 };
    std::array<double, 2> p2_2 = { p2[0] + 1, p2[1] };
    std::array<double, 2> p3_1 = { p3[0] + 1, p3[1] };
    std::array<double, 2> p3_2 = { p3[0], p3[1] + 1 };
    std::array<double, 2> p4_1 = { p4[0], p4[1] + 1 };
    std::array<double, 2> p4_2 = { p4[0] - 1, p4[1] };

    int c1_1 = getpixel(p1_1[0], p1_1[1]);
    int c1_2 = getpixel(p1_2[0], p1_2[1]);
    int c2_1 = getpixel(p2_1[0], p2_1[1]);
    int c2_2 = getpixel(p2_2[0], p2_2[1]);
    int c3_1 = getpixel(p3_1[0], p3_1[1]);
    int c3_2 = getpixel(p3_2[0], p3_2[1]);
    int c4_1 = getpixel(p4_1[0], p4_1[1]);
    int c4_2 = getpixel(p4_2[0], p4_2[1]);

	Vector res = { 0.0, 0.0 };
	Vector fri = { 0.0, 0.0 };
	Vector gra = { 0.0, 0.0 };
    int graDir = 0;

	BlockDriver();
	BlockDriver(BlockData BD);
	~BlockDriver();

    void steeringWheel();
    void renewDriver();
    void driveBlock();
    void drawBlock();
};

