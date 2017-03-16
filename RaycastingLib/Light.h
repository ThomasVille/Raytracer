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

		/** Possibilit� pour la source lumineuse de modifier sa position lors du calcul de la lumi�re.
		* Utile pour les sources lumineuses uniformes (DirectionalLight, AmbientLight)
		*/
		virtual Vec3 GetPosition(Vec3 point, Vec3 normale);

		float intensity;
	};
}
