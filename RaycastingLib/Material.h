#pragma once
#include "Color.h"

namespace RT
{
	class Material
	{
	public:
		Material();
		Material(Color color, float ambientCoefficient, float diffuseCoefficient, float specularCoefficient, float reflectionCoefficient, float shininessCoefficient);
		~Material();

		Color color;
		float ambientCoefficient;
		float diffuseCoefficient;
		float specularCoefficient;
		float reflectionCoefficient;
		float shininessCoefficient;
	};
}


