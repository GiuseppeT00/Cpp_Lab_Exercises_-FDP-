#ifndef LIST_FUNCIONS_H
#define LIST_FUNCIONS_H

#include "ArrayBased_List.h"
//#include "LLinkedBased_List.h"
//#include "DLinkedBased_Class.h"
//#include "CLinked_BasedClass.h"
#include <iostream>

struct born {
	int day;
	int month;
	int year;
};

inline void Assert(bool exp, string s) {
	if (!exp)
	{
		cout << "Assertion failed...! " << s << endl;
		exit(-1);
	}
}

class Item {
private:
	string name;
	string surname;
	born birth;
public:
	Item() { };

	Item(string n, string s, born b) { 
		name = n;
		surname = s;
		birth = b;
	}
	string get_name() const { return name; }
	string get_sur() const { return surname; }
	born get_birth() const { return birth; }
};

ostream& operator<<(ostream& os, const Item& it) {
	return os << "(" << it.get_name() << "," << it.get_sur() << "," << it.get_birth().day << "/" << it.get_birth().month << "/" << it.get_birth().year << ")";
}

bool operator<(const Item& it1, const Item& it2) {
	if (it1.get_sur() < it2.get_sur()) return true;

	else if (it1.get_sur() == it2.get_sur()) {

		if (it1.get_name() < it2.get_name()) return true;

		else if (it1.get_name() == it2.get_name()) {

			if (it1.get_birth().year < it2.get_birth().year) return true;

			else if (it1.get_birth().year == it2.get_birth().year) {

				if (it1.get_birth().month < it2.get_birth().month) return true;

				else if (it1.get_birth().month == it2.get_birth().month) {

					if (it1.get_birth().day < it2.get_birth().day) return true;

					else return false;
				}
				else return false;
			}
			else return false;

		}
		else return false;
	}
	else return false;
}

template <typename E> void listPrint(List<E>& L) {
	int c_pos = L.currPos();
	L.moveToStart();
	cout << "<< ";
	for (int i = 0; i < c_pos; i++)
	{
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	for (int i = c_pos; i < L.length(); i++)
	{
		cout << L.getValue() << " ";
		L.next();
	}
	cout << " >>" << endl;
	L.setPos(c_pos);
}

template <typename E> void listFind(List<E>& L, E item) {
	int c_pos = L.currPos();
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
	{
		if (L.getValue() == item) {
			cout << "Item" << item << " found at position " << L.currPos() + 1 << endl;
			L.setPos(c_pos);
			return;
		}
	}
	cout << "Sorry. Item not found." << endl;
	L.setPos(c_pos);
}

template <typename E> void insertOrdered(List<E>& L, E item, string order) {
	int c_pos = L.currPos();
	if (L.length() == 0) {
		L.append(item);
		return;
	}
	if (order == "asc")
	{
		for (L.moveToStart(); L.currPos() < L.length(); L.next())
			if (L.getValue() >= item) {
				L.insert(item);
				L.setPos(c_pos);
				return;
			}
		L.append(item);
		L.setPos(c_pos);
	}
	else if (order == "desc") {
		for (L.moveToStart(); L.currPos() < L.length(); L.next())
			if (L.getValue() <= item) {
				L.insert(item);
				L.setPos(c_pos);
				return;
			}
		L.append(item);
		L.setPos(c_pos);
	}
}

template <typename E> void listBubbleSort(List<E>& L) {
	E item_1, item_2, temp;
	int c_pos = L.currPos();
	for (int i = 0; i < L.length(); i++)
	{
		for (int j = 0; j < L.length() - 1 - i; j++)
		{
			L.setPos(j);
			item_1 = L.getValue();
			L.setPos(j+1);
			item_2 = L.getValue();
			if (item_1 > item_2)
			{
				temp = L.remove();
				L.insert(item_1);
				L.setPos(j);
				temp = L.remove();
				L.insert(item_2);
			}
		}
	}
	L.setPos(c_pos);
}

template <typename E> void desc_mergeLists(List<E>& L1, List<E>& L2, List<E>& L3) {
	L1.moveToStart();
	L2.moveToStart();
	do
	{
		if (L1.length() > 0 && L2.length() > 0)
		{
			if (L1.getValue() >= L2.getValue()) {
				L3.append(L1.getValue());
				L1.remove();
			}
			else {
				L3.append(L2.getValue());
				L2.remove();
			}
		}
		else if (L1.length() > 0) {
			L3.append(L1.getValue());
			L1.remove();
		}
		else {
			L3.append(L2.getValue());
			L2.remove();
		}

	} while (L1.length() > 0 || L2.length() > 0);
}

template <typename E> E maxValue(List<E>& L) {
	E max = NULL;
	int c_pos = L.currPos();
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
		if (L.getValue() > max) max = L.getValue();
	L.setPos(c_pos);
	return max;
}

template <typename E> void fillList(List<E>& L) {
	E size = maxValue(L);
	E i = size - size, c_pos = L.currPos();
	for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
		if (L.getValue() != i) L.insert(i);
		i++;
	}
	L.setPos(c_pos);
}

template <typename E> void removeDouble(List<E>& L) {
	int c_pos = L.currPos(), pos = 0;
	E it1;
	L.moveToStart();
	while (pos < L.length())
	{
		L.setPos(pos);
		it1 = L.getValue();
		L.setPos(pos + 1);
		while (L.currPos() < L.length())
		{
			if (it1 == L.getValue()) L.remove();
			else L.next();
		}
		pos++;
	}
	if (c_pos > L.length()) L.moveToEnd();
	else L.setPos(c_pos);
}

template <typename E> void insertionSort(List<E>& L) {
	int c = L.currPos();
	for (int i = 1; i < L.length(); i++) {
		for (int j = i; j > 0; j--)
		{
			L.setPos(j);
			E it1 = L.getValue();
			L.prev();
			E it2 = L.getValue();
			if (it1 < it2) {
				L.remove();
				L.insert(it1);
				L.next();
				L.remove();
				L.insert(it2);
			}
			else break;
		}
	}
	L.setPos(c);
}

#endif // !LIST_FUNCIONS_H