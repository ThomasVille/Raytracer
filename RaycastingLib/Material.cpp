#include "Material.h"

namespace RT
{
	Material::Material() : color(COLOR::BLACK)
	{
	}
	Material::Material(Color color) : color(color)
	{
	}


	Material::~Material()
	{
	}
}
