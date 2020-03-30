#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

struct Libro {
	string titolo;
	string autore;
	int anno_ed;
	int prezzo;
};

int main() {
	srand(time(NULL));
	ofstream myfile("libri.txt");
	Libro* v;
	int len, avg = 0, max, old;

	cout << "Quanti libri vuoi memorizzare? ";
	cin>> len;
	v = new Libro[len];
	for (int i = 0; i < len; i++)
	{
		cout << "Inserisci il titolo: ";
		cin>> v[i].titolo;
		cout << "Inserisci l'autore: ";
		cin>> v[i].autore;
		cout << "Inserisci l'anno edizione: ";
		cin >> v[i].anno_ed;
		v[i].prezzo = 1 + rand() % 100;
	}
	old = v[0].anno_ed;
	max = v[0].prezzo;
	for (int i = 0; i < len; i++)
	{
		if (v[i].anno_ed < old) old = v[i].anno_ed;
		if (v[i].prezzo > max) max = v[i].prezzo;
		avg += v[i].prezzo;
		myfile << "Libro " << i + 1 << endl;
		myfile << "Titolo: " << v[i].titolo << endl;
		myfile << "Autore: " << v[i].autore << endl;
		myfile << "Anno edizione: " << v[i].anno_ed << endl;
		myfile << "Prezzo: " << v[i].prezzo << endl << endl;
	}
	avg /= len;
	cout << "Prezzo medio : " << avg << endl;
	cout << "Libro piu' vecchio : " << old << endl;
	cout << "Prezzo massimo : " << max << endl;

	return 0;
}