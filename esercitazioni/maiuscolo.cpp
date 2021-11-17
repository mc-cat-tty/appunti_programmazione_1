#include <iostream>

using namespace std;

bool lowercase(char &c) {
	if (c<'A' || c>'Z')
		return false;
	
	c = c - 'A' + 'a';
	return true;
}

int main() {
	char c;
	cout << "Carattere: "; cin >> c;
	
	cout << lowercase(c) << " " << c << endl;
	return 0;
}
