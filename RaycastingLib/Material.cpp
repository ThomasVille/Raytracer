#include "Material.h"

namespace RT
{
	Material::Material() : Material(COLOR::BLACK, 1.0f, 1.0f, 1.0f, 0.0f, 10.0f)
	{
	}
	Material::Material(Color color, float ambientCoefficient, float diffuseCoefficient, float specularCoefficient, float reflectionCoefficient, float shininessCoefficient) :
		color(color), ambientCoefficient(ambientCoefficient), diffuseCoefficient(diffuseCoefficient), specularCoefficient(specularCoefficient), reflectionCoefficient(reflectionCoefficient),
		shininessCoefficient(shininessCoefficient)
	{
	}


	Material::~Material()
	{
	}
}
