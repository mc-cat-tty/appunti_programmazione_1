#include <iostream>

using namespace std;

int main() {
	int n;
	
	cout <<	"1\tOpzione A\n"
					"3\tOpzione B\n"
					"4\tOpzione C\n"
					"5\tOpzione C\n"
					"6\tOpzione D\n"
					"\n";

	cout << "Scegli un opzione: ";
	cin >> n;

	switch (n) {
		case 1:
			cout << "Opzione A";
			break;
		case 3:
			cout << "Opzione B";
			break;
		case 4:
		case 5:
			cout << "Opzione C";
			break;
		case 6:
			cout << "Opzione D";
			break;
		default:
			cout << "Scelta non valida";
	}
	cout << endl;
	
	return 0;
}
