#include <iostream>

using namespace std;

const char FIRST_CHAR = ' ';
const char LAST_CHAR = '~';

int main() {
	for (char c=FIRST_CHAR; c<=LAST_CHAR; c++) {
		cout << static_cast<int>(c) << " " << c << "\t";
		if (static_cast<int>(c-FIRST_CHAR+1)%8 == 0)
			cout << endl;
	}
	cout << endl;
	return 0;
}
