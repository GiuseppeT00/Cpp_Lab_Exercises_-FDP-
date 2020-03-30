#include "Class.h"

int main() {
	Pair<int> first_i(0,0), second_i(0,0);
	int n1, n2;
	Pair<string> first_s("",""), second_s("", "");
	string s1, s2;

	cout << "Inserisci il valore della prima coppia intera (n n): ";
	cin >> n1 >> n2;
	first_i.set_element(0, n1);
	first_i.set_element(1, n2);
	cout << "Inserisci il valore della seconda coppia intera (n n): ";
	cin >> n1 >> n2;
	second_i.set_element(0, n1);
	second_i.set_element(1, n2);

	cout << "Inserisci il valore della prima coppia stringa (s s): ";
	cin >> s1 >> s2;
	first_s.set_element(0, s1);
	first_s.set_element(1, s2);
	cout << "Inserisci il valore della seconda coppia stringa (s s): ";
	cin >> s1 >> s2;
	second_s.set_element(0, s1);
	second_s.set_element(1, s2);

	first_i.add_up(second_i);
	first_s.add_up(second_s);
	cout << "The add-up-couple between two integers couples is: ( " << first_i.get_element(0) << " , " << first_i.get_element(1) << " )" << endl;
	cout << "The add-up-couple between two strings couples is: ( " << first_s.get_element(0) << " , " << first_s.get_element(1) << " )" << endl;

	return 0;
}