#include <iostream>

using namespace std;

const int DIM = 4;

int calcola_diff_diag(const int m[][DIM], int dim) {
	int d_princ = 0;
	int d_sec = 0;
	for (int i = 0; i<dim; i++) {
		d_princ += m[i][i];
		d_sec += m[i][dim-i-1];
		// cout << i << " " << dim-i-1 << endl;
	}
	cout << d_princ << " " << d_sec << endl;
	return d_princ-d_sec;
}

int main() {
	const int m[][DIM]=	{{1, 2, 3, 4},
						 {2, 3, 4, 5},
						 {2, 3, 4, 5},
						 {2, 3, 4, 5},
						};
	cout << calcola_diff_diag(m, DIM);
}
