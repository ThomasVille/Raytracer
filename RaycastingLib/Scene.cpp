#include "Scene.h"
#include <iostream>
namespace RT
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
	}
	void Scene::AddObject(std::shared_ptr<PhysicalObject> obj)
	{
		objects.push_back(obj);
	}
	void Scene::AddLight(std::shared_ptr<Light> light)
	{
		lights.push_back(light);
	}
	void Scene::SetCamera(Camera cam)
	{
		camera = cam;
	}
	void Scene::SetBackground(Color c)
	{
		bgColor = c;
	}
	void Scene::SetAmbientLightIntensity(float i)
	{
		ambientLightIntensity = i;
	}
}

