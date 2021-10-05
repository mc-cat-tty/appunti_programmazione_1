#include <iostream>

using namespace std;

int main() {
	// [kb/s]
	const int	T1_MAX	= 60*60,// seconds
				V1_MAX	= 200,	// if t <= 60 min
				V1_MIN	= 50,	// if t > 60 min
				V2		= 100;	// always
	const int	V1_MAX_TIME_SECONDS = 60*60;
	int dim;					// dimensione film [kb]
	
	cout << "Dimensione film [kb]: ";
	cin >> dim;
	
	int t_v1_max = dim/V1_MAX;	// seconds
	if (t_v1_max <= T1_MAX)
		cout << "Server 1 in " << t_v1_max/60;
	else {
		int max_dim_v1_max = V1_MAX*V1_MAX_TIME_SECONDS;
		int dim_v1_min = dim-max_dim_v1_max;
		int t_v1_min = dim_v1_min/V1_MIN;
		int t_v2 = dim/V2;
		if (V1_MAX_TIME_SECONDS+t_v1_min <= t_v2)
			cout << "Server 1 in " << (V1_MAX_TIME_SECONDS+t_v1_min)/60;
		else
			cout << "Server 2 in " << t_v2/60;
	}
	cout << " minutes" << endl;

	return 0;
}
