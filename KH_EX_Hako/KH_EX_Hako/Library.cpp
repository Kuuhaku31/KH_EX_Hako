
#include "Library.h"

extern std::string path_1_ = "!C:/Users/apple/Documents/Pro++/KU/pictures/Map/map - 1.png";
extern std::string path_2_ = "C:/Users/apple/Documents/Pro++/KU/pictures/ika.png";
extern std::string path_3_ = "./Material/ika - a.png";
extern std::string path_4_ = "./Material/ika - b.png";
extern std::string data_path_1 = "./Data/Player.txt";
extern std::string data_path_2 = "./Data/Map - 1.txt";

std::array<IMAGE, 2> loadIKA()
{
	IMAGE ika_a;
	IMAGE ika_b;
	loadimage(&ika_a, path_3_.c_str());
	loadimage(&ika_b, path_4_.c_str());
	
	std::array<IMAGE, 2> ika = { ika_a, ika_b };
	return ika;
}

HRGN getHRGN()
{
	HRGN h = CreateRectRgn(0, 0, 0, 0);

	IMAGE map_1;
	loadimage(&map_1, path_1_.c_str());
	int width = map_1.getwidth();
	int height = map_1.getheight();

	SetWorkingImage(&map_1);
	std::cout << "Start loading..." << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (getpixel(j, i) == 0x000000)
			{
				HRGN h0 = CreateRectRgn(j, i, j + 1, i + 1);
				CombineRgn(h, h, h0, RGN_OR);
				DeleteObject(h0);
			}
		}
	}
	std::cout << "Finish loading" << std::endl;
	SetWorkingImage();

	return h;
}

HRGN getHRGN_()
{
	HRGN h = CreateRectRgn(0, 0, 0, 0);

	std::ifstream ifs(data_path_2);
	if (ifs.is_open())
	{
		std::cout << "Start loading..." << std::endl;
		int i = 0, start = 0, end = 0;
		while (ifs >> i >> start >> end)
		{
			HRGN h0 = CreateRectRgn(start, i, end + 1, i + 1);
			CombineRgn(h, h, h0, RGN_OR);
			DeleteObject(h0);
		}
		std::cout << "Finish loading" << std::endl;
	}
	else { std::cout << "Error: Cannot open file" << std::endl; }

	return h;
}

void saveMap()
{
	IMAGE map_1;
	loadimage(&map_1, path_1_.c_str());
	int width = map_1.getwidth();
	int height = map_1.getheight();
	SetWorkingImage(&map_1);

	std::ofstream ofs(data_path_2);
	if (ofs.is_open())
	{
		std::cout << "Start saving..." << std::endl;

		for (int i = 0; i < height; i++)
		{
			bool isBlack = false;
			int start = 0;
			int end = 0;
			for (int j = 0; j < width; j++)
			{
				if (getpixel(j, i) == 0x000000)
				{
					if (!isBlack)
					{
						isBlack = true;
						start = j;
					}
					end = j;
					if (j == width - 1) 
					{ 
						ofs << i << " " << start << " " << end << std::endl; 
						std::cout << i << " " << start << " " << end << std::endl;
					}
				}
				else
				{
					if (isBlack)
					{
						isBlack = false;
						ofs << i << " " << start << " " << end << std::endl;
						std::cout << i << " " << start << " " << end << std::endl;
					}
				}
			}
		}

		std::cout << "Finish saving" << std::endl;

		ofs.close();
	}
	else { std::cout << "Error: Cannot open file" << std::endl; }
}

std::vector<double> loadData(std::string path)
{
	std::vector<double> data;
	std::ifstream ifs(path);
	if (ifs.is_open())
	{
		std::cout << "Start loading..." << std::endl;

		double n;
		while (ifs >> n) { data.push_back(n); }
		ifs.close();

		std::cout << "Finish loading" << std::endl;
	}
	else { std::cout << "Error: Cannot open file" << std::endl; }
	return data;
}

void saveData(std::string path, std::vector<double> data)
{
	std::ofstream ofs(path);
	if (ofs.is_open())
	{
		std::cout << "Start saving..." << std::endl;

		for (int i = 0; i < data.size(); i++) { ofs << data[i] << std::endl; }
		ofs.close();

		std::cout << "Finish saving" << std::endl;
	}
	else { std::cout << "Error: Cannot open file" << std::endl; }
}

