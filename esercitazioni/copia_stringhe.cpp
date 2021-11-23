#include <iostream>

using namespace std;

int copia_custom(char dst[], const char src[]) {
	int i;
	for (i=0; src[i] != '\0'; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return i;
}

int main() {
	char str1[100] = "Prima";
	char str2[100] = "Seconda";
	
	cout << str1 << endl;
	cout << str2 << endl;
	
	int l1 = copia_custom(str1, str2);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << l1 << endl;
}
