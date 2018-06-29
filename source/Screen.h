#pragma once
#include "Size.h";
#include <string>

class Screen {
	//diagonal size represented in inches
	float diagonal_size;

	Size resolution;

	std::string technology;
public:
	float get_diagonal_size();

	Size get_resolution();

	std::string get_technology();
};