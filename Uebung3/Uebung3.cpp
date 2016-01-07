// Uebung3.cpp : Defines the entry point for the console application.
//
#pragma once
#include "vect.h"


int main() {
	double a_data[] = { 2, 3, 5, 9 };
	double b_data[] = { 1, 0, 0, 1 };
	double c_data[] = { 3, 0, 2, 5 };
	double d_data[4];
	Array<double> A(a_data, 4);
	Array<double> B(b_data, 4);
	Array<double> C(c_data, 4);
	Array<double> D(d_data, 4);
	D = A + B + C;
	D.print();
	D = A - B - C;
	D.print();


	//Multiply and Scalar
	int k = 5;
	double l = 3.14;
	//double a_data[] = { 2, 3, 5, 9 };
	//double b_data[] = { 1, 0, 0, 1 };
	//double c_data[] = { 3, 0, 2, 5 };
	//
	//double d_data[4];
	//Array<double> A(a_data, 4);
	//Array<double> B(b_data, 4);
	//Array<double> C(c_data, 4);
	//Array<double> D(d_data, 4);
	D = A*k;
	D.print();
	D = k*A;
	D.print();
	D = A*k + B + l*C;
	D.print();

	//Scalar Product
	/*double a_data[] = { 2, 3, 5, 9 };
	double b_data[] = { 1, 0, 0, 1 };
	Array<double> A(a_data, 4);
	Array<double> B(b_data, 4);
	*/
	
	D = A + B;
	D.print();
	//D = A^C; 
	//D = A ^ (A + B); 
	D = (A + B) ^ (A + B);
	D.print();

}

