#include <iostream>
#include <cmath>

using namespace std;


int main() {
	/* struttura dati
			n per contenere il numero
			max_div per memorizzare il massimo numero per cui tentare la divisione
			i indice del ciclo for
	*/
	int n;
	bool primo = true;  // assumiamo che n sia primo
	
	cin >> n;
	if (n>=1 && n<=3) {
		cout << n << " è primo" << endl;
		return 0;
	}
	
	if (n%2==0)
		primo = false;
	
	int max_div = static_cast<int>(sqrt(n));
	for (int i=3; i<=max_div && primo; i+=2) {
		if (n%i == 0) {
			primo = false;
		}
	}
	cout << n;
	if (primo)
		cout << " è primo";
	else
		cout << " non è primo";
	cout << endl;
}
