#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int MAX_DIM = 100;

int conta_occorrenze(const char[], char);

int main() {
	char str[MAX_DIM];
	char c;

	cout << "Inserisci la parola in cui cercare: "; cin >> str;
	cout << "Stringa: " << str << endl;
	cout << "Quale carattere devo cercare?  "; cin >> c;
	
	int occorrenze = conta_occorrenze(str, c);
	
	cout << c << " compare " << occorrenze << " volte nella stringa \"" << str << "\"" << endl;
	return 0;	
}

// case-insensitive occurrencies counter
int conta_occorrenze(const char s[], char c) {
	int len = strlen(s);
	int counter = 0;
	c = tolower(c);
	for (int i=0; i<len; i++) {
		if (tolower(s[i]) == c)
			counter++;
	}
	return counter;
}
