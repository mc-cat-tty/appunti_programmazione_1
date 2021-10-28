#include <iostream>

using namespace std;

const char maiuscolo(const char);

int main() {
	char minus, maius;
	cin >> minus;
	maius = maiuscolo(minus);
	if (maius == minus)
		cout << "Il carattere " << minus << " non è minuscolo" << endl;
	else
		cout << "Il carattere " << minus << " è minuscolo - maiuscolo: " << maius << endl;
	return 0;
}

const char maiuscolo(const char c) {
	if (c>='a' && c<='z')
		return c-('a'-'A');  // Add the shift between lowercase and uppercase letters
	return c;
}
