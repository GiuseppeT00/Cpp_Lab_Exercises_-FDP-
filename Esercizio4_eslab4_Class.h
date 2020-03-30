#ifndef ES4
#define ES4

#include <iostream>
#include <string>
using namespace std;

template <class T> class Matrix2x2 {
public:
	Matrix2x2() { };
	Matrix2x2(T x1, T x2, T x3, T x4);
	T get_value(int i, int j) const;
	void print() const;
	void add(Matrix2x2<T> x);
private:
	T m[2][2];
};

template <typename T> Matrix2x2<T>::Matrix2x2(T x1, T x2, T x3, T x4) {
	m[0][0] = x1;
	m[0][1] = x2;
	m[1][0] = x3;
	m[1][1] = x4;
}
template <typename T> T Matrix2x2<T>::get_value(int i, int j) const {
	return m[i][j];
}
template <typename T> void Matrix2x2<T>::print() const {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << "[" << m[i][j] << "] ";
		cout << endl;
	}
}
template <typename T> void Matrix2x2<T>::add(Matrix2x2<T> x) {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m[i][j] += x.get_value(i, j);
		}
	}
}

#endif // !ES4

