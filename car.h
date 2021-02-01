#pragma once
#include "framework.h"

class car
{
	int xpos_{}, ypos_{}, r_{}, g_{}, b_{};
public:
	car(int xpos, int ypos)
	{
		this->xpos_ = xpos;
		this->ypos_ = ypos;
		this->r_ = rand_colour();
		this->g_ = rand_colour();
		this->b_ = rand_colour();
	}
	car();
	void draw(HDC hdc) const;
	void set_x_pos();
	void set_y_pos();
	int get_x_pos() const;
	int get_y_pos() const;
	static int rand_colour();
	
};
