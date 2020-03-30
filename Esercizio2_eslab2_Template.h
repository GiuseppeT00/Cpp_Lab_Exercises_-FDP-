#ifndef ES2
#define ES2

#include <iostream>
#define N 10
using namespace std;

template <typename T> 
T most_common(T* v, int dim) {
	int count[N] = { 0 };
	int max_id = 0;
	for (int i = 0; i < dim - 1; i++)
		for (int j = i + 1; j < dim; j++)
			if (v[i] == v[j]) count[i]++;
	for (int i = 0; i < dim; i++)
		if (count[i] > count[max_id]) max_id = i;
	return v[max_id];
}


#endif // !ES2

