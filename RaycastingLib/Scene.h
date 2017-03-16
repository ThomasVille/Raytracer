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
		// Intensit� de la lumi�re ambiante
		float ambientLightIntensity;
		// Liste d'objets physiques
		std::vector< std::shared_ptr<PhysicalObject> > objects;
		std::vector< std::shared_ptr<Light> > lights;
		// Camera dans la sc�ne
		Camera camera;

		Scene();
		~Scene();

		/** Ajoute l'objet pass� en param�tre � la sc�ne */
		void AddObject(std::shared_ptr<PhysicalObject> obj);

		/** Ajoute une source lumineuse � la sc�ne */
		void AddLight(std::shared_ptr<Light> light);

		/** D�finie la cam�ra de la sc�ne */
		void SetCamera(Camera cam);

		/** D�finie la couleur du fond */
		void SetBackground(Color c);

		/** D�finie l'intensit� de l'illumination globale */
		void SetAmbientLightIntensity(float i);
	};
}


