#include "pch.h"
#include "CppUnitTest.h"
#include "../tasksasd/Header.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(tests1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string input = "<]{}}([])<";
			std::string output = "<[]{}{}([])<>>";
			Assert::AreEqual(makeValidSequence(input), output);
		}

		TEST_METHOD(TestMethod2)
		{
			std::string input = "";
			std::string output = "";
			Assert::AreEqual(makeValidSequence(input), output);
		}

		TEST_METHOD(TestMethod3)
		{
			std::string input = "([]{})";
			std::string output = "([]{})";
			Assert::AreEqual(makeValidSequence(input), output);
		}

		TEST_METHOD(TestMethod4)
		{
			std::string input = "(])";
			std::string output = "([])";
			Assert::AreEqual(makeValidSequence(input), output);
		}

		TEST_METHOD(TestMethod5)
		{
			std::string input = "{[<])";
			std::string output = "{[<[]()>]}";
			Assert::AreEqual(makeValidSequence(input), output);
		}

		TEST_METHOD(TestMethod6)
		{
			std::string input = "([]{})";
			std::string output = "([]{})";
			Assert::AreEqual(makeValidSequence(input), output);
		}
	};
}
