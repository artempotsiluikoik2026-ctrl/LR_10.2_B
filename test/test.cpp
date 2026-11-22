
#include "pch.h"
#include "CppUnitTest.h"
#include "../ЛР 10.2 B/Students.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102B
{
	TEST_CLASS(UnitTest102B)
	{
	public:

		void Fill(Student& s, string surname, Specialty specialty, int physics)
		{
			s.surname = surname;
			s.course = 1;
			s.specialty = specialty;
			s.physics = physics;
			s.math = 5;
			s.pedagogy = 5;
		}

		void FillAll(Student* p)
		{
			Fill(p[0], "Zakhar", COMPUTER_SCIENCE, 4);
			Fill(p[1], "Andrii", MATH_ECONOMICS, 3);
			Fill(p[2], "Olena", INFORMATICS, 4);
			Fill(p[3], "Bohdan", COMPUTER_SCIENCE, 4);
			Fill(p[4], "Iryna", INFORMATICS, 3);
		}

		TEST_METHOD(TestSort)
		{
			Student p[5];
			FillAll(p);
			Sort(p, 5);
			Assert::IsTrue(p[0].surname == "Iryna");
			Assert::IsTrue(p[1].surname == "Andrii");
			Assert::IsTrue(p[2].surname == "Bohdan"); 
			Assert::IsTrue(p[3].surname == "Zakhar");
			Assert::IsTrue(p[4].surname == "Olena");
		}

		TEST_METHOD(TestIndexSort)
		{
			Student p[5];
			FillAll(p);
			int* I = IndexSort(p, 5);
			Assert::AreEqual(4, I[0]); 
			Assert::AreEqual(1, I[1]); 
			Assert::AreEqual(3, I[2]);
			Assert::AreEqual(0, I[3]); 
			Assert::AreEqual(2, I[4]); 
			Assert::IsTrue(p[0].surname == "Zakhar"); 
			Assert::IsTrue(p[4].surname == "Iryna");
			delete[] I;
		}

		TEST_METHOD(TestBinSearch)
		{
			Student p[5];
			FillAll(p);
			Sort(p, 5); 
			Assert::AreEqual(0, BinSearch(p, 5, "Iryna", INFORMATICS, 3));
			Assert::AreEqual(1, BinSearch(p, 5, "Andrii", MATH_ECONOMICS, 3));
			Assert::AreEqual(2, BinSearch(p, 5, "Bohdan", COMPUTER_SCIENCE, 4));
			Assert::AreEqual(3, BinSearch(p, 5, "Zakhar", COMPUTER_SCIENCE, 4));
			Assert::AreEqual(4, BinSearch(p, 5, "Olena", INFORMATICS, 4));
		}

		TEST_METHOD(TestBinSearchNotFound)
		{
			Student p[5];
			FillAll(p);
			Sort(p, 5);
			Assert::AreEqual(-1, BinSearch(p, 5, "Andrii", MATH_ECONOMICS, 4));  
			Assert::AreEqual(-1, BinSearch(p, 5, "Bohdan", INFORMATICS, 4));     
			Assert::AreEqual(-1, BinSearch(p, 5, "Nobody", COMPUTER_SCIENCE, 4)); 
		}
	};
}