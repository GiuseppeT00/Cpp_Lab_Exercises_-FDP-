#ifndef FUNCTION
#define FUNCTION

#include "LQueue.h"

inline void Assert(bool exp, string s) {
	if (!exp)
	{
		cout << "Assertion failed...!" << s << endl;
		exit(-1);
	}
}

class Item {
private:
	int val;
public:
	Item(int v = 0) { val = v; }
	int key() const { return val; }
	bool operator!=(const Item& other) const;
};

bool Item::operator!=(const Item& other) const {
	if (val != other.key()) return 1;
	else return 0;
}

inline ostream& operator<<(ostream& os, Item it) {
	return os << it.key();
}

template <typename E> void queuePrint(Queue<E>& Q) {
	LQueue<E> Qt;
	E it;
	if (Q.length() > 0)
	{
		cout << "Format: first in <- ... <- last in ;" << endl;
		while (Q.length() > 0)
		{
			it = Q.dequeue();
			Qt.enqueue(it);
			cout << it;
			if (Q.length() > 0) cout << " <- ";
		}
		cout << endl;
		while (Qt.length() > 0) Q.enqueue(Qt.dequeue());
	}
	else cout << "Queue is empty...!" << endl;
}

template <typename E> bool equalQueues(Queue<E>& Q1, Queue<E>& Q2) {
	if (Q1.length() != Q2.length()) return 0;
	E it1, it2;
	for (int i = 0; i < Q1.length(); i++)
	{
		it1 = Q1.dequeue();
		it2 = Q2.dequeue();
		if (it1 != it2) return 0;
		Q1.enqueue(it1);
		Q2.enqueue(it2);
	}
	return 1;
}


#endif // !FUNCTION