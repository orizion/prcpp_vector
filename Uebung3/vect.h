#include "operators.h"
#include <iostream>

using namespace std;

template <typename T>
struct Array {
	T *m_data;
	size_t m_N;

	Array(T *data, size_t N) : m_data(data), m_N(N) {}
	~Array() { }


	template <typename Left, typename Op, typename Right>
	void operator=(Expr<Left, Op, Right, T> expr) {
		for (size_t i = 0; i < m_N; i++)
		{
			m_data[i] = expr[i];
		}
	}

	template <typename Left, typename Right>
	void operator=(Expr<Left,Scalar<T>, Right, T> expr) {
		T sum = 0;
		for (size_t i = 0; i < m_N; i++)
		{
			sum += expr[i];	
		}
		m_N = 1;
		m_data[0] = sum;
	}

	T operator[](int i) {
		return m_data[i];
	}

	void print() {
		size_t l = 0; cout << '[';
		if (m_N > 0) cout << m_data[l++];
		while (l < m_N)
		{
			cout << ',' << m_data[l++];
		}
		cout << ']' << endl;
	}
    
};



//Array Operators
template <typename Left, typename T>
Expr<Left, Plus<T>, Array<T>, T> operator+(Left a, Array<T> b) {
	return Expr<Left, Plus<T>, Array<T>, T>(a, b);
}
template <typename Left, typename T>
Expr<Left, Minus<T>, Array<T>, T> operator-(Left a, Array<T> b) {
	return Expr<Left, Minus<T>, Array<T>, T>(a, b);
}
//Expression Left
template <typename Left, typename T>
Expr<Left, Mul<T>, Array<T>, T> operator*(Left a, Array<T> b) {
	return Expr<Left, Mul<T>, Array<T>, T>(a, b);
}
//Expression Right
template <typename Right, typename T>
Expr<Array<T>, Mul<T>, Right, T> operator*(Array<T> a, Right b) {
	return Expr<Array<T>, Mul<T>, Right, T>(a, b);
}


template <typename Left, typename T>
Expr<Left, Scalar<T>, Array<T>, T> operator^(Left a, Array<T> b) {
	return Expr<Left, Scalar<T>, Array<T>, T>(a, b);
}



//Expression Operators
template <typename Left, typename T, typename XL, typename XO, typename XR>
Expr<Left, Plus<T>, Expr<XL, XO, XR,T>, T> operator+(Left a, Expr<XL, XO, XR,T> b) {
	return Expr <Left, Plus<T>, Expr<XL, XO, XR,T>, T>(a, b);
}
template <typename Left, typename T, typename XL, typename XO, typename XR>
Expr<Left, Minus<T>, Expr<XL, XO, XR,T>, T> operator-(Left a, Expr<XL, XO, XR,T> b) {
	return Expr<Left, Minus<T>, Expr<XL, XO, XR,T>, T>(a, b);
}
template <typename Left, typename T, typename XL, typename XO, typename XR>
Expr<Left, Mul<T>, Expr<XL, XO, XR,T>, T> operator*(Left a, Expr<XL, XO, XR,T> b) {
	return Expr<Left, Mul<T>, Expr<XL, XO, XR,T>, T>(a, b);
}

template <typename Left, typename T, typename XL, typename XO, typename XR>
Expr<Left, Scalar<T>, Expr<XL, XO, XR, T>, T> operator^(Left a, Expr<XL, XO, XR, T> b) {
	return Expr<Left, Scalar<T>, Expr<XL, XO, XR,T>, T>(a, b);
}

