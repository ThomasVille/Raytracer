#include "PointLight.h"


namespace RT
{
	PointLight::PointLight(Vec3 position, float intensity) : Light(position, intensity)
	{
	}


	PointLight::~PointLight()
	{
	}

	float PointLight::GetAttenuation(Vec3 point, Vec3 normale)
	{
		return 1/(point-this->position).Norme();
	}
}
