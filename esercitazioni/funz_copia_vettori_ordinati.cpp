#include <iostream>

using namespace std;

// this function will write dim1+dim2 elements into v3
void copy_ord(const int v1[], const int dim1, const int v2[], const int dim2, int v3[]) {
	int i1, i2, i3; i1 = i2 = i3 = 0;
	while (i1 < dim1 && i2 < dim2) {
		if (v1[i1] < v2[i2])
			v3[i3++] = v1[i1++];
		else
			v3[i3++] = v2[i2++];
	}

	if (i1 == dim1 && i2 == dim2)
		return;
	else if (i1 == dim1)
		for (int i=i2; i<dim2; i++)
			v3[i3++] = v2[i];
	else if (i2 == dim2)
		for (int i=i1; i<dim1; i++)
			v3[i3++] = v1[i];
}

int main() {
	const int
		DIM1 = 5, 
		DIM2 = 4,
		DIM3 = DIM1 + DIM2;
	int v1[DIM1] = {2, 3, 6, 8, 10},
		v2[DIM2] = {1, 5, 10, 15},
		v3[DIM3];
	
	copy_ord(v1, DIM1, v2, DIM2, v3);
	
	for (int i=0; i<DIM3; i++) {
		cout << v3[i] << " ";
	}
	cout << endl;
	
	return 0;
}
