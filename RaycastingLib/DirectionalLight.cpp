#include "DirectionalLight.h"

namespace RT
{
	DirectionalLight::DirectionalLight(float intensity, Vec3 direction) : Light(Vec3(), intensity), direction(direction)
	{
	}


	DirectionalLight::~DirectionalLight()
	{
	}

	float DirectionalLight::GetAttenuation(Vec3 point, Vec3 normale)
	{
		return 1.0f;
	}

}
