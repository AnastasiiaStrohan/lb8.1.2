#include "pch.h"
#include "CppUnitTest.h"
#include "../lb8.1.2/lb8.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest812
{
	TEST_CLASS(UnitTest812)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str1[] = "this is a nXo pattern";
			bool foundPattern1 = false;
			char expectedStr1[] = "this is a * pattern";


			ReplacePatternWithAsterisks(str1, foundPattern1);

			Assert::IsTrue(foundPattern1, L"Pattern should be found.");
			Assert::AreEqual(expectedStr1, str1, L"String should be modified as expected.");

			
			char str2[] = "no pattern here";
			bool foundPattern2 = false;
			char expectedStr2[] = "no pattern here";

			ReplacePatternWithAsterisks(str2, foundPattern2);

			Assert::IsFalse(foundPattern2, L"Pattern should not be found.");
			Assert::AreEqual(expectedStr2, str2, L"String should remain unchanged.");

			
			char str3[] = "an note nTo with nMo";
			bool foundPattern3 = false;
			char expectedStr3[] ="an note * with *";

			ReplacePatternWithAsterisks(str3, foundPattern3);

			Assert::IsTrue(foundPattern3, L"Pattern should be found.");
			Assert::AreEqual(expectedStr3, str3, L"String should be modified as expected.");

			
			char str4[] = "";
			bool foundPattern4 = false;
			char expectedStr4[] = "";

			ReplacePatternWithAsterisks(str4, foundPattern4);

			Assert::IsFalse(foundPattern4, L"Pattern should not be found in an empty string.");
			Assert::AreEqual(expectedStr4, str4, L"Empty string should remain unchanged.");
			
		}
	};
}
