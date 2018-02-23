#include "stdafx.h"
#include "CppUnitTest.h"
#include "readint.h"  
#include "readint.cpp"
#include <fstream> 
#include <iostream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HW03_Tester
{
	TEST_CLASS(READINT_TEST)
	{
	public:

		TEST_METHOD(TestCase1) // Test case 1: invalid input
		{
			
			ifstream ss("..\\UnitTester\\zeroinput.txt");
		
			if (ss.fail())
				throw int(-1); 
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
		
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);
			
			cin.rdbuf(orig_cin);
			
			ss.close();
		}

		TEST_METHOD(TestCase2) // Test case 2: for invalid argument
		{
			
			auto func = []() 
			{
				
				read_int("My prompt: ", 5, 1);
			};
			
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TestCase3)
		{

			ifstream ss("..\\UnitTester\\5intinput.txt");

			if (ss.fail())
				throw int(-1);
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			cin.rdbuf(orig_cin);

			ss.close();
		}

		TEST_METHOD(TestCase4)
		{
			auto func = []()
			{

				read_int("My prompt: ", 0, 0);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}


	};

}