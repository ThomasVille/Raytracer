#include "Renderer.h"


namespace RT
{
	Renderer::Renderer(cv::Mat window) : window(window)
	{

	}

	Renderer::~Renderer()
	{
	}

		/** Fait le rendu de la scène */
	void Renderer::render(Scene& scene)
	{
		int nbThreads = 8;
		int tileWidth = window.cols / (nbThreads / 2);
		int tileHeight = window.rows / (nbThreads / 2);

		for (int i = 0; i < nbThreads / 2; i++) {
			for (int j = 0; j < nbThreads / 2; j++) {
				renderChunk(scene, Rect(tileWidth*j, tileHeight*i, tileWidth, tileHeight));
			}
		}
	}

		/** Rend une partie de la scène sur la matrice window */
	void Renderer::renderChunk(Scene& scene, Rect roi)
	{
		for (int i = roi.y; i < roi.height + roi.y; i++) {
			for (int j = roi.x; j < roi.width + roi.x; j++) {
				window.at<cv::Vec3b>(i, j) = GetPixelValue(scene, j, i);
			}

		}
	}

	/** Effectue le lancé de rayon et renvoie la valeur du pixel à afficher */
	Color Renderer::GetPixelValue(RT::Scene& scene, int x, int y)
	{
		Vec3 pixelInWorld = scene.camera.TransformScreenToWorld(Vec3(x, y, 0), window.cols, window.rows);
		Vec3 cameraOrigin = scene.camera.position;
		Vec3 direction = (pixelInWorld - cameraOrigin).Normalized();
		std::vector<Intersection> intersections;

		// Calcule l'intersection avec chaque objet et stocke les intersections existantes
		for (int i = 0; i < scene.objects.size(); i++) {
			Intersection intersection = scene.objects[i]->Intersects(direction, cameraOrigin, scene.camera.nearDistance, scene.camera.farDistance);
			if (intersection.exists)
				intersections.push_back(intersection);
		}
		// Pixel de fond (aucune intersection)
		if (intersections.empty()) {
			return scene.bgColor;
		}
		
		// Récupère l'intersection la plus proche de la caméra
		Intersection nearestIntersection = *std::min_element(intersections.begin(), intersections.end(), [](Intersection &a, Intersection &b) { return a.distToCamera < b.distToCamera; });

		Vec3 V = direction * -1.0f;
		Vec3 N = nearestIntersection.target->GetNormale(nearestIntersection.position);

		float ka = 1.0f;
		float Ia = 0.5f;

		float kd = 0.5f;
		float Id = 0.0f;

		float ks = 0.5f;
		float ke = 100.0f;
		float Is = 0.0f;

		for (int i = 0; i < scene.lights.size(); i++)
		{
			Vec3 L = (scene.lights[i]->GetPosition(nearestIntersection.position, N) - nearestIntersection.position).Normalized();
			Vec3 R = L.Reflected(N);
			Vec3 H = (L + V).Normalized();
			Id += N.prodScal(L)*scene.lights[i]->intensity*scene.lights[i]->GetAttenuation(nearestIntersection.position, N);
			Is += pow(N.prodScal(H), ke)*scene.lights[i]->intensity*scene.lights[i]->GetAttenuation(nearestIntersection.position, N);
		}

		float I = ka*Ia + kd*Id + ks*Is;

		return I*nearestIntersection.target->material.color;
	}

}