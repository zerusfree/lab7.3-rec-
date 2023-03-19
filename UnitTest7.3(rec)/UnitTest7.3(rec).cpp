#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[3][3] = { {0, 2, 1},
							{2, 1, 3},
							{2, 1, 6} };
			int* a1[3] = { a[0],a[1],a[2] };
			int t1;
			t1 = CountOfRows(a1, 3, 3, 4, 0, 0, 0);
			
			Assert::AreEqual(t1, 3);
		}
	};
}
