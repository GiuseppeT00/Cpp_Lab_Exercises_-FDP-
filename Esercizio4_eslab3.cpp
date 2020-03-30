#include "DLinkedBased_Class.h"
#include "List_Functions.h"

#include <cstdlib>
#include <ctime>

void exercise4(List<Item<int>>& L) {
	int cpos = L.currPos();
	int it;
	for (L.setPos(L.length()-1); L.currPos() > 0; L.prev())
	{
		it = L.remove().get_value();
		L.prev();
		it *= L.getValue().get_value();
		L.next();
		L.insert(Item<int>(it));
	}
	L.setPos(cpos);
}


int main() {
	srand(time(NULL));
	DList<Item<int>> L1;
	int n;

	cout << "Insert the number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		L1.append(Item<int>((i + 1) * 2));
	} 
	listPrint(L1);

	exercise4(L1);
	cout << "Traformed list: " << endl;
	listPrint(L1);

	return 0;
}