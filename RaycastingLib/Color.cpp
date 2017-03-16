#include "Color.h"



namespace RT
{
	Color::Color() : Color(0,0,0)
	{
	}

	Color::Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b)
	{
	}

	Color::Color(COLOR c)
	{
		switch (c) {
		case RED:
			r = 255;
			g = 0;
			b = 0;
			break;
		case BLUE:
			r = 0;
			g = 0;
			b = 255;
			break;
		case GREEN:
			r = 0;
			g = 255;
			b = 0;
			break;
		case WHITE:
			r = 255;
			g = 255;
			b = 255;
			break;
		case BLACK:
			r = 0;
			g = 0;
			b = 0;
			break;
		case YELLOW:
			r = 255;
			g = 255;
			b = 0;
			break;
		case PINK:
			r = 255;
			g = 0;
			b = 255;
			break;
		}
	}

	Color::~Color()
	{
	}

	unsigned char Color::clamp(float a)
	{
		return ((a >= 256.0f) ? 255 : (a < 0.0f ? 0 : a));
	}


	Color::operator cv::Vec3b() const
	{
		return cv::Vec3b(b, g, r);
	}
}