#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	const char *BIN_FILENAME = "data.dat";
	const char *TXT_FILENAME = "data.txt";
	const int LEN = 5;
	const double a[LEN] = {1., .2, 3.33333333, 7.0/3.0, 0.0};
	
	// Scrittura
	ofstream f_bin(BIN_FILENAME), f_txt(TXT_FILENAME);
	if (!f_bin or !f_txt) {
		cerr << "Errore apertura file in scrittura" << endl;
		return 1;
	}
	
	for (int i=0; i<LEN; i++) {
		f_txt << a[i] << endl;
	}
	
	f_bin.write(reinterpret_cast<const char *>(a), sizeof(a[0])*LEN);

	f_bin.close();
	f_txt.close();

	// Lettura
	ifstream if_bin(BIN_FILENAME), if_txt(TXT_FILENAME);
	double d;
	cout << "File testuale" << endl;
	for (int i=LEN; i --> 0;) {
		if_txt >> d;
		cout << d << endl;
	}
	
	double a2[LEN];
	if_bin.read(reinterpret_cast<char *>(a2), sizeof(a2));
	cout << endl << "File binario" << endl;
	cout << setprecision(9);
	for (int i=0; i<LEN; i++) {
		cout << a2[i] << endl;
	}
	
	if_bin.close();
	if_txt.close();	

	return 0;
}
