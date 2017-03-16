#pragma once
#include "Object.h"

namespace RT
{
	class Light : public Object
	{
	public:
		Light(Vec3 position, float intensity);
		~Light();

		/** Renvoie l'att�nuation de la lumi�re en fonction de la position du point � �clairer.
		  */
		virtual float GetAttenuation(Vec3 point, Vec3 normale) = 0;

		float intensity;
	};
}
