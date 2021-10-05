#include <iostream>

using namespace std;

int main() {
	int a, b, sel;
	cout <<
		"1 --> +\n"
		"2 --> -\n"
		"3 --> *\n"
		"4 --> /\n"
		"5 --> resto divisione intera\n"
		"\n";
	
	cout << "Inserire a: ";
	cin >> a;

	cout << "Inserire b: ";
	cin >> b;

	cout << "Selezione: ";
	cin >> sel;
	
	switch (sel) {
		case 1:
			cout << a << " + " << b << " = " << a+b;
			break;
		case 2:
			cout << a << " - " << b << " = " << a-b;
			break;
		case 3:
			cout << a << " * " << b << " = " << a*b;
			break;
		case 4:
			if (b == 0) {
				cout << "Operazione non valida";
				break;
			}
			cout << a << " / " << b << " = " << a/b;
			break;
		case 5:
			if (b == 0) {
				cout << "Operazione non valida";
				break;
			}
			cout << a << " % " << b << " = " << a%b;
			break;
		default:
			cout << "Opzione inesistente";
	}
	cout << endl;
	// Miglioramenti: usa flag, ritorna exit code diverso da 0 in caso di errore
	
	return 0;
}
