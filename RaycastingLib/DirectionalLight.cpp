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
		// Aucune att�nuation de la lumi�re, elle est pr�sente partout dans la direction o� elle �claire
		return 1.0f;
	}

	Vec3 DirectionalLight::GetPosition(Vec3 point, Vec3 normale)
	{
		return point - direction;
	}

}
