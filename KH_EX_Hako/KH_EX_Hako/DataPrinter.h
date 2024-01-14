
#pragma once

#include "Moniter.h"

class DataPrinter : public Moniter
{
public:
	std::vector<std::string> dataName = { "NULL" };
	std::vector<std::string> data = { "NULL" };

	DataPrinter();
	DataPrinter(int x, int y, int width, int height);
	~DataPrinter();

	void printData();
	void printData(int x, int y);
	void printData(int x, int y, int width, int height);
};
