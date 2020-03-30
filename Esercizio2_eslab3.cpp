#include "List_Functions.h"
#include "LLinkedBased_List.h"

int pairControl(List<Item>& L, string s, string c) {
	Item it;
	int c_pos = L.currPos();
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
	{
		it = L.getValue();
		if (it.get_s() == s && it.get_c() == c) {
			L.setPos(c_pos);
			return 0;
		}
		else if (it.get_s() == s && it.get_c() != c) {
			L.remove();
			L.insert(Item(s, c));
			L.setPos(c_pos);
			return 2;
		}
	}
	L.append(Item(s, c));
	L.setPos(c_pos);
	return 1;
}



int main() {
	LList<Item> L1;
	int res;

	L1.append(Item("TO", "Torino"));
	L1.append(Item("PR", "Parma"));
	L1.append(Item("MI", "Milano"));
	L1.append(Item("BA", "Barletta"));
	L1.append(Item("FI", "Firenze"));
	L1.append(Item("FG", "Foggia"));
	L1.append(Item("PA", "Padova"));
	L1.append(Item("RO", "Roma"));

	listPrint(L1);

	res = pairControl(L1, "TO", "Torino");
	if (res == 0) cout << "(TO, Torino) found!" << endl;
	else if (res == 2) cout << "(TO, Torino) : TO found... Torino not found -> item modified succesfully." << endl;
	else cout << "(TO, Torino) : not found -> it's added at the end of the list." << endl;
	res = pairControl(L1, "BA", "Bari");
	if (res == 0) cout << "(BA, Bari) found!" << endl;
	else if (res == 2) cout << "(BA, Bari) : BA found... Bari not found -> item modified succesfully." << endl;
	else cout << "(BA, Bari) : not found -> it's added at the end of the list." << endl;
	res = pairControl(L1, "PA", "Palermo");
	if (res == 0) cout << "(PA, Palermo) found!" << endl;
	else if (res == 2) cout << "(PA, Palermo) : PA found... Palermo not found -> item modified succesfully." << endl;
	else cout << "(PA, Palermo) : not found -> it's added at the end of the list." << endl;
	res = pairControl(L1, "BR", "Brescia");
	if (res == 0) cout << "(BR, Brescia) found!" << endl;
	else if (res == 2) cout << "(BR, Brescia) : BR found... Brescia not found -> item modified succesfully." << endl;
	else cout << "(BR, Brescia) : not found -> it's added at the end of the list." << endl;
	listPrint(L1);

	return 0;
}