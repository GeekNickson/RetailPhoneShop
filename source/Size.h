#pragma once
#include <string>

class Size {
	float height;
	float width;
	float depth;
public:
	Size(float height, float widht, float depth);
	Size(float height, float widht);
	float get_height();
	float get_width();
	float get_depth();
	std::string to_string();
};