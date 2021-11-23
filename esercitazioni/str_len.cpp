#include <iostream>

using namespace std;

int main() {
	char str[100];
	cin >> str;
	int len;
	for (len=0; str[len] != 0; len++) ;
	cout << str << " è lunga: " << len << endl;
}
