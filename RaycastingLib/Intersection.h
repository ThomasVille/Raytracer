#pragma once
#include "Vec3.h"


namespace RT
{
	class PhysicalObject;

	class Intersection
	{
	public:
		//Intersection(Intersection& other);
		Intersection(PhysicalObject* target = nullptr, bool exists = false, Vec3 position = Vec3(0, 0, 0), float distToCamera = 0.0f);
		~Intersection();

		// L'intersection existe-t-elle ?
		bool exists;
		// Position de l'intersection si elle existe
		Vec3 position;
		// Distance avec la caméra
		float distToCamera;
		// Pointeur vers l'objet qui intersectionne
		PhysicalObject* target;
	};

}
