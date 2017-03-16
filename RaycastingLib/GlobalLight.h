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

		/** Renvoie l'atténuation de la lumière en fonction de la position du point à éclairer.
		*/
		float GetAttenuation(Vec3 point, Vec3 normale);

		/** La lumière est toujours à une distance de 1 du point éclairé
		*/
		virtual Vec3 GetPosition(Vec3 point, Vec3 normale);
	};

}

