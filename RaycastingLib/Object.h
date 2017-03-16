#pragma once
#include "Vec3.h"
namespace RT
{
	class Object
	{
	public:
		Object();
		Object(Vec3 position);
		~Object();

		Vec3 position;
	};
}


