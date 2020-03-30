#include "List_Functions.h"
#include <fstream>
#include <sstream>

int main() {
	ifstream records("agenda.txt");
	AList<Item> Agenda(100);

	if (records.is_open()) {
		string n, s, str;
		born birth;
		while (getline(records, n, ' ')) {
			getline(records, s, ' ');
			getline(records, str, '/');
			istringstream day(str);
			day >> birth.day;
			getline(records, str, '/');
			istringstream month(str);
			month >> birth.month;
			getline(records, str);
			istringstream year(str);
			year >> birth.year;
			Agenda.append(Item(n, s, birth));
		}
		listPrint(Agenda);
		cout << "Sorting Agenda..." << endl;
		insertionSort(Agenda);
		listPrint(Agenda);
	}
	else {
		cout << "Unable to open file 'agenda.txt'...!" << endl;
		exit(-1);
	}









	return 0;
}