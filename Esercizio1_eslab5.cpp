#include "List_Functions.h"
#include <ctime>
#include <cstdlib>

int main(int argc, char* argv[3]) {
	if (argc < 3) {
		cout << "Insert 3 arguments when call the program." << endl << "Format: LISTSIZE , MINVAL , MAXVAL" << endl;
		exit(-1);
	}
	srand(time(NULL));
	LList<Item> L1, L2;

	for (int i = 0; i < atoi(argv[1]); i++)
	{
		L1.append(Item(atoi(argv[2]) + rand() % atoi(argv[3])));
		L2.append(Item(atoi(argv[2]) + rand() % atoi(argv[3])));
	}
	listPrint(L1);
	listPrint(L2);

	cout << "Adding L2 values in L1..." << endl;
	addValues(L1, L2);
	listPrint(L1);

	cout << "Sorting L1..." << endl;
	insertionSort(L1);
	listPrint(L1);

	return 0;
}