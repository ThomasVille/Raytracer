#pragma once
#include "Color.h"

namespace RT
{
	class Material
	{
	public:
		Material();
		Material(Color color);
		~Material();

		Color color;
	};
}


