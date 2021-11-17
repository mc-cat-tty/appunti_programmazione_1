#include <iostream>

using namespace std;

const int init(const int v_in[], int v_out[], const int n) {
	int i_out = 0;
	for (int i=0; i<n; i++)
		if (v_in[i]%2 == 0)
			v_out[i_out++] = v_in[i];
	return i_out;
}

int main() {
	const int DIM1 = 5;
	int v1[DIM1] = {3, 2, 7, 8, 10},
		v2[DIM1];
	int dim2;
	
	dim2 = init(v1, v2, DIM1);
	
	for (int i=0; i<dim2; i++)
		cout << v2[i] << " ";
	cout << endl;
}
