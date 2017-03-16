#pragma once
#include <opencv2\opencv.hpp>
#include "Scene.h"
#include "Rect.h"

namespace RT
{
	class Renderer
	{
	public:
		cv::Mat window;

		Renderer(cv::Mat window);
		~Renderer();

		/** Fait le rendu de la scène */
		void render(Scene& scene);

		/** Rend une partie de la scène sur la matrice window */
		void renderChunk(Scene& scene, Rect roi);

		/** Effectue le lancé de rayon et renvoie la valeur du pixel à afficher */
		Color GetPixelValue(RT::Scene& scene, int x, int y);

	};

}

