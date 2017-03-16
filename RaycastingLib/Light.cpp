#include "Light.h"


namespace RT
{
	Light::Light(Vec3 position, float intensity) : Object(position), intensity(intensity)
	{
	}


	Light::~Light()
	{
	}
	Vec3 Light::GetPosition(Vec3 point, Vec3 normale)
	{
		return position;
	}
}
