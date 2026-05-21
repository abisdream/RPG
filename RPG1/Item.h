#pragma once

#include <iostream>
#include <string>

struct Item
{
	std::string name;
	int price;

	void PrintInfo() const
	{
		std::cout << name << "(" << price << "G)" << std::endl;
	}
	//½½¶óÀÓÀÇ ²öÀûÇÑ Á©¸® (30G)

};