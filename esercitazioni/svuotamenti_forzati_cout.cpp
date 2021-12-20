#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int i;
	cout << "Azz "; system("sleep 2"); cin >> i;  // sync i/o

	for (int i=0; i<1000; i++) cout << "mazzopazzolazzo ";  // scrittura chunk e riempimento buffer

	system("sleep 2");

	cout << "      Endline in arrivo    " << endl;  // '\n' alla fine dello stream di byte

	cout << "      Flush forzato        " << flush;	

	cout << "      Terminazione naturale";
	return 0;
}
