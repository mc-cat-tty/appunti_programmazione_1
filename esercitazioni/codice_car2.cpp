#include <iostream>

using namespace std;

int main() {
	int cod;
	cin >> cod;
	
	cod = cod < int(' ') ? ' ' : cod;
	cod = cod > int('~') ? '~' : cod;
	cout << static_cast<char>(cod) << endl;
	return 0;
}
