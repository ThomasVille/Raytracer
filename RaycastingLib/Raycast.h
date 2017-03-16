#pragma once
#include "Color.h"
#include "Intersection.h"
namespace RT
{
	class Raycast
	{
	public:
		Raycast(Color color, Intersection intersection);
		~Raycast();

		Color color;
		Intersection intersection;
	};

}

