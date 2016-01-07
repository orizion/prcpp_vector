#pragma once

template <typename T> struct Plus {
	static T apply(T a, T b) {
		return a + b;
	}
};
template <typename T> struct Minus {
	static T apply(T a, T b) {
		return a - b;
	}
};
template <typename T> struct Mul {
	static T apply(T a, T b) {
		return a * b;
	}
};
template <typename T> struct Scalar {
	static T apply(const T& a, const T& b) {
		return a * b;
	}
};	

//General Case
template <typename Left, typename Op, typename Right, typename T>
struct Expr {
	Left m_left;
	Right m_right;

	Expr(Left t1, Right t2) : m_left(t1), m_right(t2) {}
	T operator[](int i) { return Op::apply(m_left[i], m_right[i]); }
};

//Mult double Left
template <typename Right, typename T>
struct Expr<double, Mul<T>, Right, T> {
	double m_left;
	Right m_right;

	Expr(double t1, Right t2) : m_left(t1), m_right(t2) {}
	T operator[](int i) { return Mul<T>::apply(m_left, m_right[i]); }
};

//Mult double Right
template <typename Left, typename T>
struct Expr<Left, Mul<T>, double, T> {
	double m_right;
	Left m_left;

	Expr(Left t1, double t2) : m_left(t1), m_right(t2) {}
	T operator[](int i) { return Mul<T>::apply(m_left[i], m_right); }
};

//Mult int Left
template <typename Right, typename T>
struct Expr<int, Mul<T>, Right, T> {
	int m_left;
	Right m_right;

	Expr(int t1, Right t2) : m_left(t1), m_right(t2) {}
	T operator[](int i) { return Mul<T>::apply(m_left, m_right[i]); }
};

//Mult int Right
template <typename Left, typename T>
struct Expr<Left, Mul<T>, int, T> {
	int m_right;
	Left m_left;

	Expr(Left t1, int t2) : m_left(t1), m_right(t2) {}
	T operator[](int i) { return Mul<T>::apply(m_left[i], m_right); }
};