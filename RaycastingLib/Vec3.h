#pragma once

/*
W : largeur en pixels de la fenetre
H : hauteur...
Ecran -> Image:
X' = 1+(2/W)*X
Y' = 1-(2/H)*Y
*/
namespace RT
{
	struct Vec3
	{
		// Coordonnées
		float x, y, z;

		// Constructeurs
		Vec3();
		Vec3(float x, float y, float z);
		// Destructeur
		~Vec3();

		/** Distance vers un autre vecteur */
		float DistanceTo(Vec3 const & second);

		/** Normalise le vecteur in-place */
		void Normalize();

		/** Renvoie le vecteur normalisé */
		Vec3 Normalized();

		/** Renvoie la norme du vecteur */
		float Norme();

		/** Renvoie le vecteur réfléchi selon une normale */
		Vec3 Reflected(Vec3 normale);

		Vec3 operator+(Vec3 const & second);
		float prodScal(Vec3 const & second);
		Vec3 prodVect(Vec3 const & second);

		/** Argument dependent lookup :
		* Mécanisme qui permet d'utiliser un opérateur définir dans un namespace sans préciser le namespace en question.
		* S'appuie sur les arguments de l'opérateur pour éviter ça.
		* Exemple : std::cout << "Hi !";
		* Ici, l'opérateur << est défini dans std::, et pourtant, on a pas besoin de l'écrire.
		*/
		// friends defined inside class body are inline and are hidden from non-ADL lookup
		friend Vec3 operator-(Vec3 lhs,        // passing lhs by value helps optimize chained a+b+c
			const Vec3& rhs) // otherwise, both parameters may be const references
		{
			lhs.x -= rhs.x; // reuse compound assignment
			lhs.y -= rhs.y; // reuse compound assignment
			lhs.z -= rhs.z; // reuse compound assignment
			return lhs; // return the result by value (uses move constructor)
		}
		// friends defined inside class body are inline and are hidden from non-ADL lookup
		friend Vec3 operator*(Vec3 lhs,        // passing lhs by value helps optimize chained a+b+c
			float rhs) // otherwise, both parameters may be const references
		{
			lhs.x *= rhs; // reuse compound assignment
			lhs.y *= rhs;
			lhs.z *= rhs;
			return lhs; // return the result by value (uses move constructor)
		}
		// friends defined inside class body are inline and are hidden from non-ADL lookup
		friend Vec3 operator*(float lhs,        // passing lhs by value helps optimize chained a+b+c
			Vec3 rhs) // otherwise, both parameters may be const references
		{
			rhs.x *= lhs; // reuse compound assignment
			rhs.y *= lhs;
			rhs.z *= lhs;
			return rhs; // return the result by value (uses move constructor)
		}
	};
}



