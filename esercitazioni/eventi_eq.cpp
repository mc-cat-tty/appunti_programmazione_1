#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

/*
*	Questa funzione genera un evento di tipo 1 
*	o tipo 2 in modo equamente distribuito
*/
const int gen_evento() {
	return rand() / (RAND_MAX/2);
}

int main() {
	int n;  // numero di iterazioni
	cout << "Numero di iterazioni: "; cin >> n;
	
	// contatori dei due tipi di eventi
	int type1, type2; type1 = type2 = 0;

	srand(time(0));
	for(int i=0; i<n; i++) {
		if (gen_evento())
			type1++;
		else
			type2++;
	}
	
	cout 
		<< "type1%: " << (float)type1*100.0/n << endl
		<< "type2%: " << (float)type2*100.0/n << endl;
	
	return 0;
}
