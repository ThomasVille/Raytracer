#pragma once
#include "Light.h"

namespace RT
{
	class GlobalLight :
		public Light
	{
	public:
		GlobalLight(float intensity);
		~GlobalLight();

		/** Renvoie l'att�nuation de la lumi�re en fonction de la position du point � �clairer.
		*/
		float GetAttenuation(Vec3 point, Vec3 normale);

		/** La lumi�re est toujours � une distance de 1 du point �clair�
		*/
		virtual Vec3 GetPosition(Vec3 point, Vec3 normale);
	};

}

