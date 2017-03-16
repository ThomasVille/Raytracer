#include "Camera.h"
#include <math.h>

namespace RT {
	inline double to_radians(double degrees) {
		return degrees * (3.1415926535f / 180.0f);
	}

	Camera::Camera() : Camera(Vec3(0, 0, 0), Vec3(0, 0, 1), 50, 70, 1.0f)
	{
	}

	Camera::Camera(Vec3 position, Vec3 lookat, float focalDist, float fov, float ratio) :
		lookat(lookat), focalDist(focalDist), ratio(ratio)
	{
		this->position = position;
		this->fov = to_radians(fov);
		nearDistance = 0.01f;
		farDistance = 100.0f;
	}

	Camera::~Camera()
	{
	}


	Vec3 Camera::TransformScreenToWorld(Vec3 p, float screenWidth, float screenHeight)
	{
		// Pour l'instant, la direction est z (0,0,1)
		float sW = 2 * focalDist*tanf(fov/2);
		float sH = sW / ratio;

		Vec3 worldPoint(sW / 2.0f * ((2.0f / screenWidth) * p.x - 1.0f), sH / 2.0f * (1.0f - (2.0f / screenHeight) * p.y), focalDist);

		return worldPoint;
	}

}

