#include <iostream>

using namespace std;

int main() {
	char str[] = "Analisi dei requisiti";
	int n = 0;
	char c;
	
	cout << "Carattere: "; cin >> c;
	for (int i=0; str[i] != '\0'; i++)
		if (str[i] == c)
			n++;
	
	cout << c << " compare " << n << " volte nella stringa \"" << str << "\"" << endl;
	return 0;
}
