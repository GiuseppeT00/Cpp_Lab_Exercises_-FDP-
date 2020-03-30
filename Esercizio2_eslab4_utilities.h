#ifndef FUNCTION
#define FUNCTION

#include "LQueue.h"

class Item {
private:
	int val;
public:
	Item(int v = 0) { val = v; }
	int key() const { return val; }
};

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


#endif // !FUNCTION