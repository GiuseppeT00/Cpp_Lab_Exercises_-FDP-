#include <iostream>
#include <ctime>
#define N 5
using namespace std;

int main() {
	srand(time(NULL));
	int a[N], c[N], d[N], b[N] = { 0,-3,6,-9,12 };

	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 99;
	}
	for (int i = 0; i < N; i++)
	{
		c[i] = a[i] + b[N - 1 - i];
		if (a[i] > b[i]) d[i] = 1;
		else if (a[i] == b[i]) d[i] = 0;
		else d[i] = -1;
	}
	cout << "vettore a , b, c, d :" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ; " << b[i] << " ; " << c[i] << " ; " << d[i] << " ; " << endl;
	}

	return 0;
}