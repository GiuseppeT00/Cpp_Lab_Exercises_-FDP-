#include <iostream>
#include <string>
using namespace std;

void swap(char& c1, char& c2) {
	char temp = c1;
	c1 = c2; c2 = temp;
}

void reverseString(string& s, int l, int r) {
	if (l >= r) return;
	swap(s[l++], s[r--]);
	reverseString(s, l, r);
}

int main() {
	string str;
	getline(cin, str);
	reverseString(str, 0, str.size() - 1);
	cout << str << endl;

	return 0;
}