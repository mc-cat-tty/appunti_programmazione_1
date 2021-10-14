#include <iostream>
#include <math>

using namespace std;

// TODO: completa

int main() {
	/* struttura dati
			n per contenere il numero
			max_div per memorizzare il massimo numero per cui tentare la divisione
			i indice del ciclo for
	*/
	int n;
	cin >> n;
	if (n>=1 && n<=3) {
		cout << "primo" << endl;
		return 0;
	}
	
	if (n%2==0)
		return 0;
	
	int max_div = static_cast<int>(n);
	for (int i=4; i<n && primo; i+=2) {  // soluzione inefficiente
		if (n%i == 0) {
			primo = false;
			break;
		}
	}
	cout << n;
	if (primo)
		cout << " è primo";
	else
		cout << " non è primo";
	cout << endl;
}
