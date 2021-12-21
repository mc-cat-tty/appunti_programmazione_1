#include <iostream>

using namespace std;

int main() {
	const char s[] = "test_prova";  // 10 caratteri
	int len;
	for (len=0; s[len] != '\0'; len++) ;
	cout << "La stringa ha " << len << " caratteri" << endl;
	return 0;
}
