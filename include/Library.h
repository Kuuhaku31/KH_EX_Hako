
#pragma once

#include "tools.h"

//extern IMAGE map_1;
extern std::string path_1_;

//extern IMAGE map_2;
extern std::string path_2_;
extern std::string path_3_;
extern std::string path_4_;
extern std::string data_path_1;
extern std::string data_path_2;

std::array<IMAGE, 2> loadIKA();

HRGN getHRGN();
HRGN getHRGN_();

void saveMap();

std::vector<double> loadData(std::string path);
void saveData(std::string path, std::vector<double> data);