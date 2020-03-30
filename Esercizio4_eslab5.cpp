#include "Utility.h"

int main() {
	ifstream myfile("studenti.txt");
	LList<Item> Top;
	Item* Students;
	int size, cnt = 0;
	string name, str1, str2;  int age; float avg; //To use for reading the file
	int num_scelti, eta_max;

	cout << "Insert chosen number of students to view, and the max age: ";
	cin >> num_scelti >> eta_max;

	if (myfile.is_open()) {
		myfile >> size;
		Students = new Item[size];
		while ((myfile >> name >> str1 >> str2) && (cnt < size)) {
			istringstream token1(str1); token1 >> age;
			istringstream token2(str2); token2 >> avg;
			Students[cnt] = Item(name, age, avg);
			cnt++;
		}
	}
	else {
		cout << "Unable to open the file...!" << endl;
		exit(-1);
	}

	quickSort(Students, 0, size - 1); cout << endl << endl;
	for (int i = 0; i < size; i++) cout << Students[i] << endl;

	cnt = 0;
	while ((Top.length() < num_scelti) && (cnt < size))
	{
		if (Students[cnt].get_age() < eta_max) Top.append(Students[cnt]);
		cnt++;
	}
	cout << endl;
	for (Top.moveToStart(); Top.currPos() < Top.length(); Top.next()) cout << Top.getValue() << " ";

	return 0;
}