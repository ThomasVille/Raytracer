#pragma once
#include "Light.h"
namespace RT
{
	class PointLight :
		public Light
	{
	public:
		PointLight(Vec3 position, float intensity);
		~PointLight();

		/** Renvoie l'att�nuation de la lumi�re en fonction de l'orientation de la lumi�re par rapport � l'objet.
		* \param objectToLight Vecteur unitaire allant de l'intersection vers la lumi�re
		*/
		float GetAttenuation(Vec3 point, Vec3 normale);

	};
}
