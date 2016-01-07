#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Uebung3\vect.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vektortests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Add)
		{
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };
			double c_data[] = { 3, 0, 2, 5 };
			double d_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);
			D = A + B + C;
			for (size_t i = 0; i < D.m_N; i++)
			{
				Assert::IsTrue(D[i] == A[i] + B[i] + C[i]);
			}			
		}
		TEST_METHOD(Subtract) {
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };
			double c_data[] = { 3, 0, 2, 5 };
			double d_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);
			D = A - B - C;
			for (size_t i = 0; i < D.m_N; i++)
			{
				Assert::IsTrue(D[i] == A[i] - B[i] - C[i]);
			}
		}
		TEST_METHOD(Multiply) {
			int k = 5;
			double l = 3.14;
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };

			double c_data[4];
			double d_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);
			C = k*A;
			D = B*l;
			for (size_t i = 0; i < D.m_N; i++)
			{
				Assert::IsTrue(C[i] == k*A[i]);
				Assert::IsTrue(D[i] == l*B[i]);
			}
			
		}
		TEST_METHOD(Scalar) {
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };
			double c_data[4];
			double d_data[4];
			double e_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);
			Array<double> E(e_data, 4);
			double sum = 0;

			C = A^B;
			for (size_t i = 0; i < A.m_N; i++)
			{
				sum += A[i] * B[i];
			}
			Assert::IsTrue(sum == C[0]);	
			
			sum = 0;
			D = A ^ (A + B);
			for (size_t i = 0; i < A.m_N; i++)
			{
				sum += A[i] * (A[i]+B[i]);
			}
			Assert::IsTrue(sum == D[0]);
			
			sum = 0;
			E = (A + B) ^ (A + B);
			for (size_t i = 0; i < A.m_N; i++)
			{
				sum += (A[i] + B[i]) * (A[i] + B[i]);
			}
			Assert::IsTrue(sum == E[0]);
		}
		TEST_METHOD(MixedOperations) {
			int k = 5;
			double l = 3.14;
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };

			double c_data[4];
			double d_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);

			D = k*A + B + l*C;
			double sum;
			for (size_t i = 0; i < D.m_N; i++)
			{
				Assert::IsTrue(D[i]==k*A[i] + B[i] + l*C[i]);
			}
			D.print();
		}
	};
}