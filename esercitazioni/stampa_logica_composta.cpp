#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cout << "Inserisci valori di a, b e c: ";
	cin >> a >> b >> c;
	cout<< "a<b oppure b<c " 
		<< (a<b || b<c) << endl;
	return 0;
}
