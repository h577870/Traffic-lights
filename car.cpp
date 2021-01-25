#include "car.h"
#include "framework.h"

void car::draw(HDC hdc) const
{
	const HGDIOBJ stockbrush = GetStockObject(DC_BRUSH);
	SelectObject(hdc, stockbrush);
	SetDCBrushColor(hdc, RGB(0,0,0));
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
