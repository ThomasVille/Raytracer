#pragma once
#include "Light.h"

namespace RT
{
	class DirectionalLight : public Light
	{
	public:
		DirectionalLight(float intensity, Vec3 direction);
		~DirectionalLight();

		/** Renvoie l'atténuation de la lumière en fonction de la position du point à éclairer.
		*/
		float GetAttenuation(Vec3 point, Vec3 normale);

		Vec3 direction;
	};


}
