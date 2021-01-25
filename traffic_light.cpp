#include "traffic_light.h"

traffic_light::traffic_light(const int state, int xpos, int ypos)
{
	this->xpos_ = xpos;
	this->ypos_ = ypos;
	this->state_ = state;
}

void traffic_light::set_state()
{
	if (state_ == 3) state_ = 0;
	else this->state_++;
}

void traffic_light::draw(HDC hdc) const
{
	const HGDIOBJ stockbrush = GetStockObject(DC_BRUSH);
    SelectObject(hdc, stockbrush);
	switch (state_)
	{
	case 0:
		{
			SetDCBrushColor(hdc, RGB(0,0,0));
			Rectangle(hdc, xpos_,ypos_,xpos_ - 50,ypos_ - 150);
		    SetDCBrushColor(hdc, RGB(255,0,0));
		    Ellipse(hdc, xpos_ - 5, ypos_ - 105, xpos_ - 45, ypos_ - 145);
		    SetDCBrushColor(hdc, RGB(255,255,255));
		    Ellipse(hdc, xpos_ - 5, ypos_ - 55, xpos_ - 45, ypos_ - 95);
		    Ellipse(hdc, xpos_ - 5, ypos_ - 5, xpos_ - 45, ypos_ - 45);
		}
		break;
	case 1:
		{
			SetDCBrushColor(hdc, RGB(0,0,0));
			Rectangle(hdc, xpos_,ypos_,xpos_ - 50,ypos_ - 150);
		    SetDCBrushColor(hdc, RGB(255,0,0));
		    Ellipse(hdc, xpos_ - 5, ypos_ - 105, xpos_ - 45, ypos_ - 145);
		    SetDCBrushColor(hdc, RGB(255,255,0));
		    Ellipse(hdc, xpos_ - 5, ypos_ - 55, xpos_ - 45, ypos_ - 95);
			SetDCBrushColor(hdc, RGB(255,255,255));
		    Ellipse(hdc, xpos_ - 5, ypos_ - 5, xpos_ - 45, ypos_ - 45);
		}
		break;
	case 2:
		{
			SetDCBrushColor(hdc, RGB(0,0,0));
			Rectangle(hdc, xpos_,ypos_,xpos_ - 50,ypos_ - 150);
			SetDCBrushColor(hdc, RGB(255,255,255));
			Ellipse(hdc, xpos_ - 5, ypos_ - 105, xpos_ - 45, ypos_ - 145);
		    Ellipse(hdc, xpos_ - 5, ypos_ - 55, xpos_ - 45, ypos_ - 95);
			SetDCBrushColor(hdc, RGB(0,255,0));
		    Ellipse(hdc, xpos_ - 5, ypos_ - 5, xpos_ - 45, ypos_ - 45);
		}
		break;
	case 3:
		{
			SetDCBrushColor(hdc, RGB(0,0,0));
			Rectangle(hdc, xpos_,ypos_,xpos_ - 50,ypos_ - 150);
			SetDCBrushColor(hdc, RGB(255,255,255));
			Ellipse(hdc, xpos_ - 5, ypos_ - 105, xpos_ - 45, ypos_ - 145);
			SetDCBrushColor(hdc, RGB(255,255,0));
		    Ellipse(hdc, xpos_ - 5, ypos_ - 55, xpos_ - 45, ypos_ - 95);
			SetDCBrushColor(hdc, RGB(255,255,255));
		    Ellipse(hdc, xpos_ - 5, ypos_ - 5, xpos_ - 45, ypos_ - 45);
		}
		break;
	default:
		break;
	}
}

int traffic_light::get_state() const
{
	return this->state_;
}
