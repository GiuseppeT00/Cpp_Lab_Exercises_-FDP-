#include "LStack.h"
#include "Stack_Functions.h"

int main() {
	LStack<Item> S1;
	int n;
	
	while (cin >> n && n != 0) S1.push(Item(n));

	cout << "Your stack S1: " << endl;
	stackPrint(S1);
	//cout << "Your stack S2: " << endl;
	//stackPrint(S2);
	//cout << "\nTrasfered S1 in S2: " << endl;
	//stackTransfer(S1, S2);
	//stackPrint(S2);
	//cout << "\nYour stack S1 after transfer: " << endl;
	//stackPrint(S1);

	cout << "Reversed S1: " << endl;
	stackReverse(S1);
	stackPrint(S1);

	return 0;
}