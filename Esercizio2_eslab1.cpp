#include <iostream>
#include <sstream>
#include <string>
#define N 31
using namespace std;

void insert_day(int a[], string ch);

int main() {
	int v1[N] = { 0 }, v2[N] = { 0 };
	string chose;
	cout << "Collega 1:" << endl;
	do
	{
		cout << "Inserisci un giorno libero (quit per terminare): ";
		cin >> chose;
		insert_day(v1, chose);
	} while (chose != "quit");
	cout << "Collega 2:" << endl;
	do
	{
		cout << "Inserisci un giorno libero (quit per terminare): ";
		cin >> chose;
		insert_day(v2, chose);
	} while (chose != "quit");
	for (int i = 0; i < N; i++)
	{
		if (v1[i] == 1 && v1[i] == v2[i]) cout << "Giorno " << i + 1 << " libero ad entrambi!" << endl;
	}
	return 0;
}

void insert_day(int a[], string ch) {
	int day;
	if (ch != "quit")
	{
		istringstream conv(ch);
		conv >> day;
		a[day-1] = 1;
	}
}