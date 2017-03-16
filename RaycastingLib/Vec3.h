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
		// Coordonn�es
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

		/** Renvoie le vecteur normalis� */
		Vec3 Normalized();

		/** Renvoie la norme du vecteur */
		float Norme();

		/** Renvoie le vecteur r�fl�chi selon une normale */
		Vec3 Reflected(Vec3 normale);

		Vec3 operator+(Vec3 const & second);
		float prodScal(Vec3 const & second);
		Vec3 prodVect(Vec3 const & second);

		/** Argument dependent lookup :
		* M�canisme qui permet d'utiliser un op�rateur d�finir dans un namespace sans pr�ciser le namespace en question.
		* S'appuie sur les arguments de l'op�rateur pour �viter �a.
		* Exemple : std::cout << "Hi !";
		* Ici, l'op�rateur << est d�fini dans std::, et pourtant, on a pas besoin de l'�crire.
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



