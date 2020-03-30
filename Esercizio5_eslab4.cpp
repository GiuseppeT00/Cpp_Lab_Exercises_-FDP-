#include "LQueue.h"
#include "Queue_Functions.h"

int main() {
	LQueue<Item> Q1, Q2;
	int s1, s2, it;

	cout << "Insert the size of Q1 and Q2 queues (format: Q1len Q2len):";
	cin >> s1 >> s2;

	cout << "Insert " << s1 << " values for Q1: " << endl;
	for (int i = 0; i < s1; i++)
	{
		cin >> it;
		Q1.enqueue(Item(it));
	}
	queuePrint(Q1);

	cout << "Insert " << s2 << " values for Q2: " << endl;
	for (int i = 0; i < s2; i++)
	{
		cin >> it;
		Q2.enqueue(Item(it));
	}

	queuePrint(Q2);
	
	if (equalQueues(Q1, Q2)) cout << "Q1 and Q2 queues are equals!" << endl;
	else cout << "Q1 and Q2 aren't equals..." << endl;

	return 0;
}