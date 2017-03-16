#include "Intersection.h"
#include "PhysicalObject.h"

namespace RT
{
	/*Intersection::Intersection(Intersection & other)
	{
		target = other.target;
		exists = other.exists;
		position = other.position;
		distToCamera = other.distToCamera;
	}*/
	Intersection::Intersection(PhysicalObject* target, bool exists, Vec3 position, float distToCamera):
		target(target), exists(exists), position(position), distToCamera(distToCamera)
	{
	}

	Intersection::~Intersection()
	{
	}

}