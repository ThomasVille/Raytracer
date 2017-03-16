#include "GlobalLight.h"


namespace RT
{
	GlobalLight::GlobalLight(float intensity):Light(Vec3(), intensity)
	{
	}


	GlobalLight::~GlobalLight()
	{
	}
	float GlobalLight::GetAttenuation(Vec3 point, Vec3 normale)
	{
		return 1.0f;
	}
	Vec3 GlobalLight::GetPosition(Vec3 point, Vec3 normale)
	{
		return point + normale;
	}
}
