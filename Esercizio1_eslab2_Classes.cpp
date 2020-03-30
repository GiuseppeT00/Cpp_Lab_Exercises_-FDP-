#include "Classes.h"

//Funzioni membro classe Money

void Money::set_euros(int e) {
	euros = e;
}

int Money::get_cents() const {
	return cents;
}

void Money::set_cents(int c) {
	cents = c;
}

//Funzioni membro CreditCard
void CreditCard::print() const {
	cout << "Nome proprietario: " << owner << endl;
	cout << "Numero carta: " << card << endl;
}

Money CreditCard::get_totalcharges() {
	return payment;
}

void CreditCard::charge(string item, int e, int c) {
	cout << "Causale: " << item << "; Costo: " << e << "," << c << endl;
	Money transaction(e, c);
	payment = payment + transaction;
	cout << "Totale aggiornato.";
}