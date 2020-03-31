#ifndef MY_FUNCTIONS
#define MY_FUNCTIONS

#include "SinglyLinked_List.h"
#include <iostream>

struct time {
    int min = 0;
    int s = 0;
    int cs = 0;
    float tot = 0;
};

inline void Assert(bool val, string s) {
    if (!val) {
        cout << "Assertion failed...! " << s << endl;
        exit(-1);
    }
}

class Item {
private:
    string name;
    time rec;

public:
    Item() { }
    Item(string n, time r) {
        name = n;
        rec = r;
    }
    string get_name() const { return name; }
    time get_rec() const { return rec; }
};

ostream& operator<<(ostream& os, const Item& it) {
    return os << "(" << it.get_name() << ";" << it.get_rec().min << "." << it.get_rec().s << "." << it.get_rec().cs << ";" << it.get_rec().tot << ")";
}

inline bool operator<(const Item& it1, const Item& it2) {
    if (it1.get_rec().tot < it2.get_rec().tot) return true;
    else return false;
}

template <typename E> void listPrint(LList<E>& L) {
    int c = L.currPos();
    cout << "Format: ( name ; time: min.s.cs ; total time )" << endl << "<< ";
    for (L.moveToStart(); L.currPos() < L.length(); L.next())
    {
        if (c == L.currPos()) cout << "| ";
        E it = L.getValue();
        cout << it << " ";
    }
    cout << ">>" << endl;
    L.moveToPos(c); 
}

template <typename E> void listSwap(List<E>& L, int p1, int p2) { //p1 -> pos of item1, p2 -> pos of item2
    int c = L.currPos(); //Save curr pos to dont't lose it
    L.moveToPos(p2);
    E it2 = L.remove();
    L.moveToPos(p1);
    E it1 = L.remove();
    L.insert(it2);
    L.moveToPos(p2);
    L.insert(it1);
    L.moveToPos(c); //reset curr pos
}

template <typename E> int partition(List<E>& L, int l, int r) {
    int i = l - 1, j = r;
    int p_index = r;
    L.moveToPos(p_index); E pivot = L.getValue();
    E it1 = pivot , it2 = pivot;

    while (i < j) {
        do {
            if (i == j) break;
            i++;
            L.moveToPos(i);
            it1 = L.getValue();
        } while (it1 < pivot); //it1 -> v[i]

        do {
            if (i == j) break;
            j--;
            L.moveToPos(j);
            it2 = L.getValue();
        } while (pivot < it2); //it2 -> v[j]

        if (i != j) listSwap(L, i, j);
    }
    if (i != p_index) listSwap(L, i, p_index);
    return i;
}

template <typename E> void quickSort(List<E>& L, int l, int r) {
    if (l >= r) return;
    int p = partition(L, l, r);
    quickSort(L, l, p - 1);
    quickSort(L, p + 1, r);
}



#endif // !MY_FUNCTIONS