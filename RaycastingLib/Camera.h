#pragma once
#include "Vec3.h"
#include "Object.h"
namespace RT
{
	class Camera : public Object
	{
	public:
		Camera();
		/** Initialise la cam�ra avec des angles en degr�s*/
		Camera(Vec3 position, Vec3 lookat, float focalDist, float fov, float ratio);
		~Camera();

		/** Passe le point du rep�re de l'�cran au rep�re du monde 3D */
		Vec3 TransformScreenToWorld(Vec3 p, float screenWidth, float screenHeight);

		Vec3 lookat;
		float focalDist;
		float fov;
		float ratio;
		float nearDistance, farDistance;
	};
}


