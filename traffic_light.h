#pragma once
#include <Windows.h>

class traffic_light
{
	int xpos_; //left pos
	int ypos_; //top pos
	int state_;
	HDC hdc_;
public:
	traffic_light(int state, int xpos, int ypos, HDC hdc);
	void draw_initial() const;
};
