#include "LStack.h"
#include "Stack_Functions.h"


int stackFactorial(Stack<int>& S) {
	int factorial = 1;
	while (S.length() > 0) factorial *= S.pop();
	return factorial;
}


int main() {
	LStack<int> S1;
	int n;

	cout << "Insert until what integer do you want to insert: ";
	cin >> n;

	for (int i = 0; i < n; i++) S1.push(i+1);
	stackPrint(S1);

	cout << "Factorial of " << n << " is equal to " << stackFactorial(S1) << endl;




	return 0;
}