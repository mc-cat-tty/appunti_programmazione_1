#include <iostream>

using namespace std;

int main() {
	// [kb/s]
	const int	V1_MAX	= 200,	// if t <= 60 min
				V1_MIN	= 50,	// if t > 60 min
				V2		= 100;	// always
	const int	V1_MAX_TIME_SECONDS = 60*60;
	const int	SECS_FOR_MIN = 60;
	int	dim,					// dimensione film [kb]
		server_index,
		tempo_sec;

	cout << "Dimensione film [kb]: ";
	cin >> dim;
	
	int t_v1_max = dim/V1_MAX;	// seconds
	if (t_v1_max <= V1_MAX_TIME_SECONDS)
		{server_index = 1; tempo_sec = t_v1_max;}
	else {
		int max_dim_v1_max = V1_MAX*V1_MAX_TIME_SECONDS;
		int dim_v1_min = dim-max_dim_v1_max;
		int t_v1_min = dim_v1_min/V1_MIN;
		int t_v2 = dim/V2;
		// cout << t_v1_min;
		if (V1_MAX_TIME_SECONDS+t_v1_min <= t_v2)
			{server_index = 1; tempo_sec = V1_MAX_TIME_SECONDS+t_v1_min;}
		else
			{server_index = 2; tempo_sec = t_v2;}
	}
	cout << "Server " << server_index << " in " << tempo_sec/SECS_FOR_MIN << " minutes" << endl;
	// break point is 1080000 bytes (when t is equal to 10800 seconds)
	return 0;
}
