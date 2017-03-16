#include "stdafx.h"
#include "CppUnitTest.h"
#include "../RaycastingLib/Vec3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Creation)
		{
			RT::Vec3 a;
			RT::Vec3 b(1.0f, 25.0f, 45.0f);

			Assert::AreEqual(b.x, 1.0f, 0.01f);
			Assert::AreEqual(b.y, 25.0f, 0.01f);
			Assert::AreEqual(b.z, 45.0f, 0.01f);

			Assert::AreEqual(a.x, 0.0f, 0.01f);
			Assert::AreEqual(a.y, 0.0f, 0.01f);
			Assert::AreEqual(a.z, 0.0f, 0.01f);
		}

		TEST_METHOD(Addition)
		{
			RT::Vec3 a(1.0f, 2.0f, 3.0f);
			RT::Vec3 b(1.0f, 25.0f, 45.0f);

			RT::Vec3 c = a + b;

			Assert::AreEqual(c.x, 2.0f, 0.01f);
			Assert::AreEqual(c.y, 27.0f, 0.01f);
			Assert::AreEqual(c.z, 48.0f, 0.01f);
		}

		TEST_METHOD(ProduitScalaire)
		{
			RT::Vec3 a(1.0f, 2.0f, 3.0f);
			RT::Vec3 b(3.0f, 2.0f, 1.0f);

			float c = a.prodScal(b);

			Assert::AreEqual(c, 10.0f, 0.01f);
		}

		TEST_METHOD(ProduitVectoriel)
		{
			RT::Vec3 a(5.0f, -6.0f, 3.0f);
			RT::Vec3 b(-2.0f, 7.0f, 4.0f);

			RT::Vec3 c = a.prodVect(b);

			Assert::AreEqual(-45.0f, c.x, 0.01f);
			Assert::AreEqual(-26.0f, c.y, 0.01f);
			Assert::AreEqual(23.0f,  c.z, 0.01f);
		}
	};
}