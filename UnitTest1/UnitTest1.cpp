#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.2.1/lab_11.2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student stud;
			Assert::AreEqual(Vidminno(stud, 5, "stud.bit"), 60.00);
		}
	};
}
