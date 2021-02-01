#include "car.h"

#include "framework.h"

car::car()
= default;

void car::draw(HDC hdc) const
{
	const HGDIOBJ stockbrush = GetStockObject(DC_BRUSH);
	SelectObject(hdc, stockbrush);
	SetDCBrushColor(hdc, RGB(this->r_,this->g_,this->b_));
	Rectangle(hdc, xpos_, ypos_, xpos_ - 10, ypos_ - 10);	
}

void car::set_x_pos()
{
	this->xpos_= xpos_ + 20;
}

void car::set_y_pos()
{
	this->ypos_ = ypos_ + 20;
}

int car::get_x_pos() const
{
	return this->xpos_;
}

int car::get_y_pos() const
{
	return this->ypos_;
}

int car::rand_colour()
{
	return rand() % 256;
}





