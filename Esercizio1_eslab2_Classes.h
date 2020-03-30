#ifndef ES1
#define ES1

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class Money
{
public:
	Money(int, int); //costruttore
	int get_euros() { return euros; };
	void set_euros(int);
	int get_cents() const;
	void set_cents(int);
private:
	int euros, cents;
};

Money::Money(int e = 0, int c = 0)
{
	euros = e;
	cents = c;
}

class CreditCard
{
public:
	CreditCard(string, string);
	void print() const;
	Money get_totalcharges();
	void charge(string, int, int);
private:
	string owner, card;
	Money payment;
};

CreditCard::CreditCard(string o, string c)
{
	owner = o;
	card = c;
}

Money operator+(Money m1, Money m2) {
	int e = m1.get_euros() + m2.get_euros();
	int c = m1.get_cents() + m2.get_cents();
	e += c / 100;
	c %= 100;
	Money sum(e, c);
	return sum;
}

ostream& operator<<(ostream& os, Money m) {
	cout << m.get_euros << "," << m.get_cents << " euros" << endl;
	return os;
}


#endif // !ES1

