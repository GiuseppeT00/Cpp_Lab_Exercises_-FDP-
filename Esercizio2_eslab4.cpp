#include "LQueue.h"
#include "Queue_Functions.h"

int main() {
	LQueue<Item> Q1;
	int n;

	while (cin >> n && n != 0) {
		Q1.enqueue(Item(n));
	}

	cout << "Queue Q1 (length = "<<Q1.length()<<" ) : " << endl;
	queuePrint(Q1);
	cout << "Front value : " << Q1.frontValue() << endl;
	cout << "\nReversed queue Q1 (length = " << Q1.length() << " ) : " << endl;
	Q1.reverse();
	queuePrint(Q1);
	cout << "Front value : " << Q1.frontValue() << endl;




	return 0;
}