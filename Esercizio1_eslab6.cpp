#include "Esercizio1_eslab6_utilities.h"
#include <fstream>
#include <sstream>

int main() {
	ifstream records("50rn.txt"); //This file is named as 'Esercizio1_eslab6_need1.txt'.
	ofstream top("top_ten.txt"); //This file isn't included because it's created automatically
	LList<Item> Athletes;
	time rec;
	string name, str_min, str_s, str_cs; //Variables starting with 'str' are temporany. We need them to read the file and convert in int.

	if (records.is_open())
	{
		while (getline(records, name, ';')) {

			getline(records, str_min, ' ');
			istringstream m(str_min); m >> rec.min;

			getline(records, str_s, ' ');
			istringstream s(str_s); s >> rec.s;

			getline(records, str_cs);
			istringstream cs(str_cs); cs >> rec.cs;

			rec.tot = ((rec.min * 60 * 100) + (rec.s * 100) + rec.cs) / (float)100;

			Athletes.append(Item(name, rec));
		}
		records.close();
		quickSort(Athletes, 0, Athletes.length() - 1);
		listPrint(Athletes);
	}
	else {
		cout << "Unable to open the file...!" << endl;
		exit(-1);
	}
	
	cout << "Top 10 scores (format: name time(sec) ) :" << endl;
	top << "Top 10 scores (format: name time(sec) ) :" << endl;
	Athletes.moveToStart();
	while (Athletes.currPos() < 10)
	{
		Item play = Athletes.getValue();
		cout << play.get_name() << " " << play.get_rec().tot << endl;
		top << play.get_name() << " " << play.get_rec().tot << endl;
		Athletes.next();
	}
	Athletes.clear();
	listPrint(Athletes);

	return 0;
}