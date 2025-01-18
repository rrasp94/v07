
#include "CppUnitTest.h"
#include "..\app\money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;



namespace UnitTests
{
	TEST_CLASS(MoneyTests)
	{
	public:

		TEST_METHOD(Constructor)
		{
			money m(5, 50);
			Assert::AreEqual(5, m.get_eur());
			Assert::AreEqual(50, m.get_ct());
			money m2(0, 0);
			Assert::AreEqual(0, m2.get_eur());
			Assert::AreEqual(0, m2.get_ct());
		}

		TEST_METHOD(OperatorPlusEqual)
		{
			money m1(5, 50);
			money m2(2, 75);
			m1 += m2;
			Assert::AreEqual(8, m1.get_eur());
			Assert::AreEqual(25, m1.get_ct());
			m1 += money(1, 50);
			Assert::AreEqual(9, m1.get_eur());
			Assert::AreEqual(75, m1.get_ct());
		}

		TEST_METHOD(OperatorMinusEqual)
		{
			money m1(10, 0);
			money m2(5, 50);
			m1 -= m2;
			Assert::AreEqual(4, m1.get_eur());
			Assert::AreEqual(50, m1.get_ct());
			m1 -= money(4, 50);
			Assert::AreEqual(0, m1.get_eur());
			Assert::AreEqual(0, m1.get_ct());
		}

		TEST_METHOD(OperatorStreamInput)
		{
			std::istringstream input("5 50");
			money m;
			input >> m;
			Assert::AreEqual(5, m.get_eur());
			Assert::AreEqual(50, m.get_ct());
			std::istringstream input2("-2 -50");
			money m2;
			input2 >> m2;
			Assert::AreEqual(-3, m2.get_eur());
			Assert::AreEqual(50, m2.get_ct());
		}

		TEST_METHOD(OperatorStreamOutput)
		{
			money m(5, 5);
			std::ostringstream output;
			output << m;
			Assert::AreEqual(std::string("5 eur, 05 ct"), output.str());
			money m2(-3, 50);
			std::ostringstream output2;
			output2 << m2;
			Assert::AreEqual(std::string("-3 eur, 50 ct"), output2.str());
		}

		TEST_METHOD(EdgeCases)
		{
			money m1(0, 0);
			money m2(0, 0);
			m1 += m2;
			Assert::AreEqual(0, m1.get_eur());
			Assert::AreEqual(0, m1.get_ct());
			m1 -= m2;
			Assert::AreEqual(0, m1.get_eur());
			Assert::AreEqual(0, m1.get_ct());
		}

		TEST_METHOD(ZeroValueOperations)
		{
			money m1(0, 0);
			money m2(0, 0);
			m1 += m2;
			Assert::AreEqual(0, m1.get_eur());
			Assert::AreEqual(0, m1.get_ct());
			m1 -= m2;
			Assert::AreEqual(0, m1.get_eur());
			Assert::AreEqual(0, m1.get_ct());
		}

		TEST_METHOD(addition_overflow)
		{
			money m1(99, 50);
			money m2(0, 75);
			m1 += m2;
			Assert::AreEqual(100, m1.get_eur());
			Assert::AreEqual(25, m1.get_ct());
			m1 += money(0, 50);
			Assert::AreEqual(100, m1.get_eur());
			Assert::AreEqual(75, m1.get_ct());
		}

		TEST_METHOD(subtraction_underflow)
		{
			money m1(0, 50);
			money m2(1, 0);
			m1 -= m2;
			Assert::AreEqual(-1, m1.get_eur());
			Assert::AreEqual(50, m1.get_ct());
			m1 -= money(0, 51);
			Assert::AreEqual(-2, m1.get_eur());
			Assert::AreEqual(99, m1.get_ct());
		}

		TEST_METHOD(assignment_operator)
		{
			money m1(5, 10);
			money m2 = m1;
			Assert::AreEqual(m1.get_eur(), m2.get_eur());
			Assert::AreEqual(m1.get_ct(), m2.get_ct());
			m2 = money(-10, 50);
			Assert::AreEqual(-10, m2.get_eur());
			Assert::AreEqual(50, m2.get_ct());
		}
	};
}