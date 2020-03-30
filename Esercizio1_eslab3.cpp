#include "LLinkedBased_List.h"
#include "List_Functions.h"

#include <cstdlib>
#include <ctime>


void desc_mergeLists(List<int>& L1, List<int>& L2, List<int>& L3) {
	do
	{
		if (L1.length() > 0 && L2.length() > 0)
		{
			if (L1.getValue() >= L2.getValue()) insertOrdered(L3, L1.remove(),"desc");
			else insertOrdered(L3, L2.remove(), "desc");
		}
		else if(L1.length() > 0) insertOrdered(L3, L1.remove(), "desc");
		else insertOrdered(L3, L2.remove(), "desc");

	} while (L1.length() > 0 || L2.length() > 0);
}

int main() {
	srand(time(NULL));
	LList<int> L1, L2, L3;
	int s1, s2;

	cout << "Insert the size of L1 and L2 (format: s1 s2): ";
	cin >> s1 >> s2;

	cout << "L1:" << endl;
	for (int i = 0; i < s1; i++) L1.append(1 + rand() % 99);
	listPrint(L1);
	cout << "L2:" << endl;
	for (int i = 0; i < s2; i++) L2.append(1 + rand() % 99);
	listPrint(L2);

	cout << "L3 (L1 merged with L2 desc order): " << endl;
	desc_mergeLists(L1, L2, L3);
	listPrint(L3);

	cout << "These are L1 and L2 lists now: ";
	listPrint(L1);
	listPrint(L2);

	return 0;
}