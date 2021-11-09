#include <iostream>
#include <ctype.h>

using namespace std;

const char MIN_CHAR = ' ';
const char MAX_CHAR = '~';

bool alfanum(char c) ;
bool alfabetico(char c) ;
bool cifra_dec(char c) ;
bool cifra_esadec(char c) ;
bool minuscolo(char c) ;
bool maiuscolo(char c) ;

int main() {
	char c;
	cin >> c;
	
	cout << "alfanum alfabetico dec hex minusc maiusc" << endl;
	
	cout << alfanum(c) << " ";
	cout << alfabetico(c) << " ";
	cout << cifra_dec(c) << " ";
	cout << cifra_esadec(c) << " ";
	cout << minuscolo(c) << " ";
	cout << maiuscolo(c) << " ";
	cout << endl;
	
	cout << (bool)isalnum(c) << " ";
	cout << (bool)isalpha(c) << " ";
	cout << (bool)isdigit(c) << " ";
	cout << (bool)isxdigit(c) << " ";
	cout << (bool)islower(c) << " ";
	cout << (bool)isupper(c) << " ";
	cout << endl;
}

bool alfanum(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool alfabetico(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool cifra_dec(char c) {
	return (c >= '0' && c <= '9');
}

bool cifra_esadec(char c) {
	return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

bool minuscolo(char c) {
	return (c >= 'a' && c <= 'z');
}

bool maiuscolo(char c) {
	return (c >= 'A' && c <= 'Z');
}
