#pragma once
#include <vector>
#include <memory>
#include "PhysicalObject.h"
#include "Color.h"
#include "Camera.h"
#include "Light.h"


namespace RT
{
	class Scene
	{
	public:
		// Couleur du fond de l'image
		Color bgColor;
		// Intensité de la lumière ambiante
		float ambientLightIntensity;
		// Liste d'objets physiques
		std::vector< std::shared_ptr<PhysicalObject> > objects;
		std::vector< std::shared_ptr<Light> > lights;
		// Camera dans la scène
		Camera camera;

		Scene();
		~Scene();

		/** Ajoute l'objet passé en paramètre à la scène */
		void AddObject(std::shared_ptr<PhysicalObject> obj);

		/** Ajoute une source lumineuse à la scène */
		void AddLight(std::shared_ptr<Light> light);

		/** Définie la caméra de la scène */
		void SetCamera(Camera cam);

		/** Définie la couleur du fond */
		void SetBackground(Color c);

		/** Définie l'intensité de l'illumination globale */
		void SetAmbientLightIntensity(float i);
	};
}


