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

		return CastRay(scene, cameraOrigin, direction, 2).color;
	}

	Raycast Renderer::CastRay(RT::Scene& scene, Vec3 origin, Vec3 direction, int depth)
	{
		std::vector<Intersection> intersections;

		if(depth <= 0)
			return Raycast(COLOR::BLACK, Intersection());


		// Calcule l'intersection avec chaque objet et stocke les intersections existantes
		for (int i = 0; i < scene.objects.size(); i++) {
			// TODO On utilise les distances near et far alors qu'on devrait calculer la distance à chaque fois
			Intersection intersection = scene.objects[i]->Intersects(direction, origin, scene.camera.nearDistance, scene.camera.farDistance);
			if (intersection.exists)
				intersections.push_back(intersection);
		}
		// Pixel de fond (aucune intersection)
		if (intersections.empty()) {
			return Raycast(scene.bgColor, Intersection());
		}

		// Récupère l'intersection la plus proche de la caméra
		Intersection nearestIntersection = *std::min_element(intersections.begin(), intersections.end(), [](Intersection &a, Intersection &b) { return a.distToCamera < b.distToCamera; });

		/*GetAmbientIntensity();
		GetDiffuseIntensity();
		GetSpecularIntensity();*/

		Vec3 V = direction * -1.0f;
		Vec3 N = nearestIntersection.target->GetNormale(nearestIntersection.position);

		float ka = nearestIntersection.target->material.ambientCoefficient;
		float Ia = scene.ambientLightIntensity;

		float kd = nearestIntersection.target->material.diffuseCoefficient;
		float Id = 0.0f;

		float ks = nearestIntersection.target->material.specularCoefficient;
		float ke = nearestIntersection.target->material.shininessCoefficient;
		float Is = 0.0f;

		float Ir = 0.0f;
		Color reflectionColor;

		for (int i = 0; i < scene.lights.size(); i++)
		{
			Vec3 L = (scene.lights[i]->GetPosition(nearestIntersection.position, N) - nearestIntersection.position).Normalized();
			Raycast pointToLight = CastRay(scene, nearestIntersection.position, L, 1);

			// Vérifie dès maintenant si la lumière est visible. Si elle ne l'est pas, on peut tout de suite passer à la suivante
			// Autrement dit, si le rayon allant du point à la lumière croise un objet, alors la lumière n'est pas visible
			// TODO Checker que l'intersection n'est pas plus loin que la lumière. Dans ce cas la lumière est visible
			if (pointToLight.intersection.exists && pointToLight.intersection.distToCamera < (scene.lights[i]->GetPosition(nearestIntersection.position, N) - nearestIntersection.position).Norme())
				continue;

			Vec3 R = L.Reflected(N);

			// Applique les réflections uniquement si besoin
			if (nearestIntersection.target->material.reflectionCoefficient > 0.01f) {
				Raycast pointToReflection = CastRay(scene, nearestIntersection.position, R, depth-1);
				reflectionColor = pointToReflection.color;
				Ir = 1 / pointToReflection.intersection.distToCamera;
			}

			Vec3 H = (L + V).Normalized();

			Id += N.prodScal(L)*scene.lights[i]->intensity*scene.lights[i]->GetAttenuation(nearestIntersection.position, N);
			Is += pow(N.prodScal(H), ke)*scene.lights[i]->intensity*scene.lights[i]->GetAttenuation(nearestIntersection.position, N);
		}

		float I = ka*Ia + kd*Id + ks*Is + Ir;

		return Raycast(I*nearestIntersection.target->material.color, nearestIntersection);
	}

}