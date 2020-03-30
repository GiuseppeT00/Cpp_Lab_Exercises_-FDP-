#include "LQueue.h"
#include "Queue_Functions.h"

int main() {
	LQueue<float> Q1;
	int n;
	float val;

	cout << "How much numbers do you want to insert? ";
	cin >> n;
	cout << "Insert " << n << " numbers (separated with a space): " << endl;
	for (int i = 0; i < n; i++) {
		cin >> val;
		Q1.enqueue(val);
	}
	queuePrint(Q1);

	while (Q1.length() != 1) {
		TwoByTwo_sum(Q1);
		TwoByTwo_difference(Q1);
		TwoByTwo_multiplication(Q1);
		TwoByTwo_division(Q1);
	}
	queuePrint(Q1);

	return 0;
}