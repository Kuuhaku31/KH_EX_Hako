
#pragma once

#include "Object.h"

class Block : public Object
{
public:
	int lineColor = 0x000000;
	double width = 10.0;
	double height = 10.0;

	std::array<double, 2> p1 = { 0.0, 0.0 };
	std::array<double, 2> p2 = { 0.0, 0.0 };
	std::array<double, 2> p3 = { 0.0, 0.0 };
	std::array<double, 2> p4 = { 0.0, 0.0 };

	Block();
	Block(BlockData BD);
	~Block();

	void moveBlock(Vector f);
	void renewBlock();

	virtual void drawBlock();

	void printData();
};

