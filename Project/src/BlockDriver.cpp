#include "BlockDriver.h"

BlockDriver::BlockDriver()
{
    skin_a = loadIKA()[0];
    skin_b = loadIKA()[1];
    guides = new Guides();
}

BlockDriver::BlockDriver(BlockData BD) : Block(BD)
{
    skin_a = loadIKA()[0];
    skin_b = loadIKA()[1];
    guides = new Guides();
}

BlockDriver::~BlockDriver()
{
}

void BlockDriver::steeringWheel()
{
    std::array<double, 2> u = { 0, 0 };

    if (mbox.w) { u[1] -= 1; }
    if (mbox.s) { u[1] += 1; }
    if (mbox.a) { u[0] -= 1; }
    if (mbox.d) { u[0] += 1; }

    if (mbox.space && jumpTimer == 0 && jump2 > 0)
    {
        jumpTimer = 15;
        jump2--;
        energy -= 5.0;

        if (gra.mod != 0.0)
        {
            if (graDir > 0) { v = getVector(v.mod * cos(v.angle), 0.0); }
            else { v = getVector(0.0, v.mod * sin(v.angle)); }
        }

        moveBlock(multiplyVector(subVector(gra), 20));
    }

    double n = 1;
    if (mbox.shift) { n = 10; }

    moveBlock(multiplyVector(getUnitVector(u), FORCE_1 * n));

    moveBlock(res);

    int c = WALL_DATACOLOR;
    if (c1_1 == c || c1_2 == c || c2_1 == c || c2_2 == c || c3_1 == c || c3_2 == c || c4_1 == c || c4_2 == c) { moveBlock(fri); }
    else { moveBlock(gra); }
}

void BlockDriver::renewDriver()
{
    p1_1 = { p1[0] - 1, p1[1] };
    p1_2 = { p1[0], p1[1] - 1 };
    p2_1 = { p2[0], p2[1] - 1 };
    p2_2 = { p2[0] + 1, p2[1] };
    p3_1 = { p3[0] + 1, p3[1] };
    p3_2 = { p3[0], p3[1] + 1 };
    p4_1 = { p4[0], p4[1] + 1 };
    p4_2 = { p4[0] - 1, p4[1] };

    c1_1 = getpixel(p1_1[0], p1_1[1]);
    c1_2 = getpixel(p1_2[0], p1_2[1]);
    c2_1 = getpixel(p2_1[0], p2_1[1]);
    c2_2 = getpixel(p2_2[0], p2_2[1]);
    c3_1 = getpixel(p3_1[0], p3_1[1]);
    c3_2 = getpixel(p3_2[0], p3_2[1]);
    c4_1 = getpixel(p4_1[0], p4_1[1]);
    c4_2 = getpixel(p4_2[0], p4_2[1]);

    int c = WALL_DATACOLOR;

    if (c1_1 == c || c1_2 == c || c2_1 == c || c2_2 == c || c3_1 == c || c3_2 == c || c4_1 == c || c4_2 == c) { jump2 = 2; }

    if (c1_2 == c && c2_1 == c) { graDir = +1; }
    if (c2_2 == c && c3_1 == c) { graDir = -2; }
    if (c3_2 == c && c4_1 == c) { graDir = +2; }
    if (c4_2 == c && c1_1 == c) { graDir = -1; }

    res = getResistanceForce(v, width * height, KUZ_1);

    fri = getFrictionalForce(v, FRICTIONAL_FORCE_1);

    switch (graDir)
    {
    case +1: gra = getVector(0.0, -GRAVITATION_1); break;
    case -2: gra = getVector(+GRAVITATION_1, 0.0); break;
    case +2: gra = getVector(0.0, +GRAVITATION_1); break;
    case -1: gra = getVector(-GRAVITATION_1, 0.0); break;
    case 0: gra = { 0.0, 0.0 }; break;
    }

    if (jumpTimer > 0) { jumpTimer--; }
    if (energy < 10.0) { energy += 0.01; }
    if (energy > 10.0) { energy = 10.0; }
    if (energy < 00.0) { energy = 00.0; }
}

void BlockDriver::driveBlock()
{
    int c = WALL_DATACOLOR;

    if (c1_1 == c && c1_2 == c || c2_1 == c && c2_2 == c || c3_1 == c && c3_2 == c || c4_1 == c && c4_2 == c)
    {
        if (graDir > 0) { v = getVector(v.mod * cos(v.angle), 0.0); }
        if (graDir < 0) { v = getVector(0.0, v.mod * sin(v.angle)); }

        switch (graDir)
        {
        case +1: y++; break;
        case -2: x--; break;
        case +2: y--; break;
        case -1: x++; break;
        }
    }

    steeringWheel();

    renewBlock();
    drawBlock();

    guides->renewGuides(x, y, mbox.mx, mbox.my);
    guides->drawGuides();
}

void BlockDriver::drawBlock()
{
    putimage(p1[0], p1[1], &skin_b, SRCAND);
    putimage(p1[0], p1[1], &skin_a, SRCPAINT);

    printData();
}
