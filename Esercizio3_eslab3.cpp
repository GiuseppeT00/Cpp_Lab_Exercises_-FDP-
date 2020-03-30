#include "ArrayBased_List.h"
#include "List_Functions.h"

#include <cstdlib>
#include <ctime>

int maxItemValue(List<Item<int>>& L) {
	int it, c_pos = L.currPos(), max = 0;
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
	{
		it = L.getValue().get();
		if (it > max) max = it;
	}
	return max;
}

int main() {
	srand(time(NULL));
	AList<Item<int>>* array;
	int* max_values;
	int n, size, max = 0, index;

	cout << "Insert the number of lists: ";
	cin >> n;
	array = new AList<Item<int>>[n];
	max_values = new int[n];

	cout << "Insert the number of elements for each list (ex: 3 lists -> 10 20 5): ";
	for (int i = 0; i < n; i++) {
		cin >> size;
		for (int j = 0; j < size; j++) array[i].append(Item<int>(1 + rand() % 99));
		listPrint(array[i]);
		max_values[i] = maxItemValue(array[i]);
		cout << "Max value of list n." << i+1 << " :" << max_values[i] << endl;
		if (max_values[i] > max) 
		{
			max = max_values[i];
			index = i;
		}
	}
	cout << "The max value is reached by list n." << index + 1 << " and it's equal to " << max << endl;
	listPrint(array[index]);

	
	return 0;
}