#ifndef ES3
#define ES3

#include <iostream>
#include <string>
#define N 2
using namespace std;

template <typename T> class Pair {
public:
	Pair() { };
	Pair(T,T);
	void set_element(int position, T value);
	T get_element(int position) const;
	void add_up(const Pair<T>& the_pair);
private:
	T couple[N];
};

template<typename T> Pair<T>::Pair(T value1, T value2) {
	couple[0] = value1;
	couple[1] = value2;
};
template<typename T> void Pair<T>::set_element(int position, T value) {
	couple[position] = value;
}
template<typename T> T Pair<T>::get_element(int position) const {
	return couple[position];
}
template<typename T> void Pair<T>::add_up(const Pair<T>& the_pair) {
	couple[0] += the_pair.get_element(0);
	couple[1] += the_pair.get_element(1);
}

#endif // !ES3