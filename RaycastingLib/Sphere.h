#pragma once
#include "Vec3.h"
#include "PhysicalObject.h"
namespace RT
{
	class Sphere : public PhysicalObject
	{
	public:
		Sphere(Vec3 position, Material material,  float radius);
		~Sphere();

		/** Renvoie l'intersection entre la droite pass�e en param�tre et la sph�re */
		Intersection Intersects(Vec3 direction, Vec3 origin, float near, float far);

		/** Renvoie la normale � un endroit donn� */
		virtual Vec3 GetNormale(Vec3 position);

		float radius;
	};

}
