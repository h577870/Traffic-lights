#pragma once
#include "framework.h"

class traffic_light
{
	int xpos_; //left pos
	int ypos_; //top pos
	int state_;
public:
	traffic_light(int state, int xpos, int ypos);
	void set_state();
	void draw(HDC hdc) const;
	int get_state() const;
};
