#include "Sphere.h"

namespace RT
{
	Sphere::Sphere(Vec3 position, Material material, float radius)
	{
		this->radius = radius;
		this->material = material;
		this->position = position;
	}


	Sphere::~Sphere()
	{
	}

	Intersection Sphere::Intersects(Vec3 direction, Vec3 origin, float near, float far)
	{
		Vec3 X = origin - this->position;
		// Coefficients du polynome
		float a = pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2);
		float b = 2 * (X.prodScal(direction));
		float c = pow(X.x, 2) + pow(X.y, 2) + pow(X.z, 2) - pow(radius, 2);

		// Discriminant
		float delta = pow(b, 2) - 4 * a*c;

		// Si le rayon intersecte la sphère
		if (delta > 0.0f) {
			// Calcule les intersections
			float x1 = (-b - sqrt(delta)) / (2 * a);
			float x2 = (-b + sqrt(delta)) / (2 * a);

			// Sélectionne le point le plus proche de l'origine tout en étant dans [near,far]
			float minimum = min(withinOrHuge(x1, near, far, -1.0f), withinOrHuge(x2, near, far, -1.0f));
			// Si ce minimum respecte bien toutes les conditions, on renvoie l'intersection
			if (minimum > 0.0f) {
				return Intersection(this, true, origin + direction*minimum, minimum);
			}
		}

		// Dans tous les autres cas on renvoie une intersection qui n'existe pas (exists == false)
		return Intersection();
	}
	Vec3 Sphere::GetNormale(Vec3 position)
	{
		return (position - this->position).Normalized();
	}
}
