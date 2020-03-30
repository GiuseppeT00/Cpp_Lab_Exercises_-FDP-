#include "List_Functions.h"
#include <ctime>
#include <cstdlib>

int main() {
	srand(time(NULL));
	int size;
	LList<Item> L;

	cout << "Items number = ";
	cin >> size;
	for (int i = 0; i < size; i++) L.append(Item(rand() % 99));
	listPrint(L);

	desc_insertionSort(L);
	listPrint(L);


	return 0;
}