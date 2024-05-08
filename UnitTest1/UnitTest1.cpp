#include "pch.h"
#include "CppUnitTest.h"
#include "..\\2SlabAP_12.11\main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<Book> library{ {123456, "Taras Shevchenko", "Kobzar", 1840, 10},
								 {234567, "Lesya Ukrainka", "Forest Song", 1912, 8} };
			removeBook(library, 123456);
			Assert::AreEqual(static_cast<size_t>(1), library.size());
		}
	};
}
