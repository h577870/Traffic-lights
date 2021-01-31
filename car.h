#pragma once
#include "framework.h"

class car
{
	int xpos_, ypos_;
public:
	car(int xpos, int ypos)
	{
		this->xpos_ = xpos;
		this->ypos_ = ypos;
	}
	void draw(HDC hdc) const;
	void set_x_pos();
	void set_y_pos();
	int get_x_pos() const;
	int get_y_pos() const;
	
};
