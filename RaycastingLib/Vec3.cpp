#include "Vec3.h"
#include <math.h>
namespace RT
{

	Vec3::Vec3() : Vec3(0, 0, 0)
	{
	}

	Vec3::Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float Vec3::DistanceTo(Vec3 const & second)
	{
		return sqrt(pow(x-second.x, 2) + pow(y - second.y, 2) + pow(z - second.z, 2));
	}

	void Vec3::Normalize()
	{
		float n = Norme();
		x /= n;
		y /= n;
		z /= n;
	}

	Vec3 Vec3::Normalized()
	{
		float n = Norme();
		return Vec3(x/n, y/n, z/n);
	}

	float Vec3::Norme()
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	Vec3 Vec3::Reflected(Vec3 normale)
	{
		return (2*(normale*(normale.prodScal(*this)))-(*this)).Normalized();
	}

	Vec3 Vec3::operator+(Vec3 const & second)
	{
		return Vec3(this->x + second.x, this->y + second.y, this->z + second.z);
	}

	float Vec3::prodScal(Vec3 const & second)
	{
		return x*second.x + this->y*second.y + this->z*second.z;
	}

	Vec3 Vec3::prodVect(Vec3 const & second)
	{
		return Vec3(y*second.z -  z*second.y, z*second.x - x*second.z, x*second.y - y*second.x);
	}


	Vec3::~Vec3()
	{
	}

}