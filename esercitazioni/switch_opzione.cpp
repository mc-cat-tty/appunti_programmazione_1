#include <iostream>

using namespace std;

int main() {
	int n;
	
	cout <<	"1\tOpzione A\n"
					"2\tOpzione B\n"
					"3\tOpzione C\n"
					"4\tOpzione D\n"
					"\n";

	cout << "Scegli un opzione: ";
	cin >> n;

	switch (n) {
		case 1:
			cout << "Opzione A";
			break;
		case 2:
			cout << "Opzione B";
			break;
		case 3:
			cout << "Opzione C";
			break;
		case 4:
			cout << "Opzione D";
			break;
		default:
			cout << "Scelta non valida";
	}
	cout << endl;
	
	return 0;
}
