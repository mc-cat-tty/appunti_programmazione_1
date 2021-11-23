#include <iostream>

using namespace std;

int main() {
	char str[100] = "Selva oscura di Dante";
	int len = 0;
	
	for (int i=0; ; i++, len++) {
		cout << str[i];
		if (str[i] == ' ' || str[i] == '\0') {
			cout << "\tlen : " << len << endl;
			len = 0;
		}
		if (str[i] == '\0')
			break;
	}
}
