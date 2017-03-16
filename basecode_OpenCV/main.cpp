/**
* INF4034 - Imagerie numérique
* TDAO - Introduction à OpenCV
* Enseignant : TEXIER Aurelien
*
* Illustre plusieurs opérations sur les images.
* Moyenne, médiane, histogramme, filtrage, webcam.
* L'image d'entrée doit de préférence être carrée pour entrer sans déformation dans la grille d'affichage.
*
* @author  Camille Chesnel, Thomas Ville
* @since   2017-03-01
*/
#include <opencv2\opencv.hpp>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <future>
#include <memory>
#include <math.h>
#include "../RaycastingLib/Scene.h"
#include "../RaycastingLib/Renderer.h"
#include "../RaycastingLib/Camera.h"
#include "../RaycastingLib/Vec3.h"
#include "../RaycastingLib/Sphere.h"
#include "../RaycastingLib/PointLight.h"
#include "../RaycastingLib/DirectionalLight.h"
#include "main.h"
using namespace std;

int main(int argc, char **argv)
{
	cout << "Raytracer v0.0\nThomas VILLE\n";
	cv::Mat window(500,500, CV_8UC3);

	RT::Scene scene;
	RT::Renderer renderer(window);
	RT::Camera cam(RT::Vec3(0, 0, 0), RT::Vec3(0, 0, 1), 50, 70, 100.0f/100.0f);
	RT::Material white(RT::COLOR::WHITE), yellow(RT::COLOR::YELLOW), pink(RT::COLOR::PINK);

	std::shared_ptr<RT::PointLight> ptL = std::make_shared<RT::PointLight>(RT::Vec3(-5, 5, 0), 10.0f);
	//std::shared_ptr<RT::DirectionalLight> drL = std::make_shared<RT::DirectionalLight>(1.0f, RT::Vec3(0, 1, 0));

	scene.SetBackground(RT::Color(77,100,141));
	scene.SetCamera(cam);

	scene.AddLight(ptL);
	scene.AddLight(std::make_shared<RT::PointLight>(RT::Vec3(5, 0, 10), 2.0f));
	//scene.AddLight(drL);

	scene.AddObject(std::make_shared<RT::Sphere>(RT::Vec3(0, 0, 10), yellow, 1.0f));
	scene.AddObject(std::make_shared<RT::Sphere>(RT::Vec3(0.5, 0, 9), pink, 0.5f));
	scene.AddObject(std::make_shared<RT::Sphere>(RT::Vec3(-2, 2, 10), white, 3.0f));
	

	// Rend la scène
	renderer.render(scene);
	// Dessine des infos
	cv::rectangle(window, cv::Rect(0, 0, 500, 30), cv::Scalar(255, 255, 255));
	cv::putText(window, "Image : 0", cv::Point(3,18), cv::HersheyFonts::FONT_HERSHEY_PLAIN, 1.0f, cv::Scalar(255,255,255));
	// Affiche l'image
	cv::imshow("Window", window);
	cv::waitKey();

	// Sauvegarde l'image
	cv::imwrite("output.png", window);

	return EXIT_SUCCESS;
}

