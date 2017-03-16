#pragma once
#include <opencv2\opencv.hpp>

namespace RT
{
	enum COLOR { RED, BLUE, GREEN, WHITE, BLACK, YELLOW, PINK };

	struct Color
	{
	public:
		Color();
		Color(unsigned char r, unsigned char g, unsigned char b);
		Color(COLOR c);
		~Color();

		/** Restreint la valeur aux bornes valides d'une couleur 8 bits [0,255]*/
		static unsigned char clamp(float a);

		/** Conversion vers le type cv::Vec3b */
		operator cv::Vec3b() const;

		unsigned char r;
		unsigned char g;
		unsigned char b;


		// friends defined inside class body are inline and are hidden from non-ADL lookup
		friend Color operator*(Color lhs,        // passing lhs by value helps optimize chained a+b+c
			float rhs) // otherwise, both parameters may be const references
		{
			lhs.r = clamp(lhs.r*rhs); // reuse compound assignment
			lhs.g = clamp(lhs.g*rhs);
			lhs.b = clamp(lhs.b*rhs);
			return lhs; // return the result by value (uses move constructor)
		}
		// friends defined inside class body are inline and are hidden from non-ADL lookup
		friend Color operator*(float lhs,        // passing lhs by value helps optimize chained a+b+c
			Color rhs) // otherwise, both parameters may be const references
		{
			rhs.r = clamp(rhs.r*lhs); // reuse compound assignment
			rhs.g = clamp(rhs.g*lhs);
			rhs.b = clamp(rhs.b*lhs);
			return rhs; // return the result by value (uses move constructor)
		}

	};
}


