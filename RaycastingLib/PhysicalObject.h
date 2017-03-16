#pragma once
#include "Object.h"
#include "Material.h"
#include "Intersection.h"

namespace RT
{
	inline float min(float a, float b) { return a < b ? a : b; }
	inline float withinOrHuge(float x, float min, float max, float outOfRangeValue) { return (x > min && x < max) ? x : outOfRangeValue; }

	class PhysicalObject :	public Object
	{
	public:
		PhysicalObject();
		~PhysicalObject();

		/** Renvoie l'intersection entre la droite passée en paramètre et l'objet */
		virtual Intersection Intersects(Vec3 direction, Vec3 origin, float near, float far) = 0;

		/** Renvoie la normale à un endroit donné */
		virtual Vec3 GetNormale(Vec3 position) = 0;

		Material material;
	};

}
