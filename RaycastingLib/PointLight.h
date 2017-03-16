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

		/** Renvoie l'atténuation de la lumière en fonction de l'orientation de la lumière par rapport à l'objet.
		* \param objectToLight Vecteur unitaire allant de l'intersection vers la lumière
		*/
		float GetAttenuation(Vec3 point, Vec3 normale);

	};
}
