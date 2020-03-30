#ifndef UTILITY_H
#define UTILITY_H

#include "llist.h"
#include <fstream>
#include <sstream>

class Item {
private:
	string surname;
	int age;
	float avg;
public:
	Item(string s = "", int a = -1, float v = -1) {
		surname = s;
		age = a;
		avg = v;
	}
	string get_sur() const { return surname; }
	int get_age() const { return age; }
	float get_avg() const { return avg; }

};

ostream& operator<<(ostream& os, const Item& it) {
	return os << "(" << it.get_sur() << "; " << it.get_age() << "; " << it.get_avg() << ")";
}

inline bool operator>(const Item& it1, const Item& it2) {
	if (it1.get_avg() > it2.get_avg()) return true;
	else return false;
}

template <typename E, typename T> void swap(E& A, T& B) {
	E temp = A; A = B; B = temp;
}

template <typename E> int partition(E v[], int l, int r) {
	int i = l - 1, j = r;
	int p_index = r;
	E pivot = v[r];
	while (i < j)
	{
		do
		{
			if (i >= j) break;
			i++;
		} while (v[i] > pivot);
		do
		{
			if (j <= i) break;
			j--;
		} while (pivot > v[j]);
		if (i != j) swap(v[i], v[j]);
	}
	if (i != p_index) swap(v[i], v[p_index]);
	return i;
}

template <typename E> void quickSort(E v[], int l, int r) {
	if (l >= r) return;

	int p = partition(v, l, r);

	quickSort(v, l, p - 1);
	quickSort(v, p + 1, r);
}



#endif // !UTILITY_H