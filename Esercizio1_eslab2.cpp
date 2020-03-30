#include "Classes.h"

int main() {
	ifstream source("example.txt");
	CreditCard visa("Giuseppe", "4590 2234 5671 2098");
	string item;
	int e, c;

	visa.print();

	while (source >> item >> e >> c) {
		visa.charge(item, e, c);
	}

	return 0;
}