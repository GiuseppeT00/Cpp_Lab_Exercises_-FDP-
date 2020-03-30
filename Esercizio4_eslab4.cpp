#include "LStack.h"
#include "Stack_Functions.h"

Item fibonacci(Item k) {
	if (k.key() <= 2) { return Item(1); }
	return Item(fibonacci(k.key() - 1).key() + fibonacci(k.key() - 2).key());
}

int main() {
	LStack<Item> S1;
	int n;
	
	cout << "Insert the number of fibonacci sequence that you want to see. ";
	cin >> n;

	for (int i = 1; i <= n; i++) S1.push(fibonacci(Item(i)));

	stackPrint(S1);

	return 0;
}