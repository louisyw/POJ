/*
 *Cable master (POJ 164)
 */

#include <cstdio>
#include <math.h>
#include <limits.h>
const int MAX_N = 10000;
int N, K;
double L[MAX_N];

bool is_feasible(double x){
	int num = 0;
	for(int i = 0 ;i < N; i++){
		num += (int) (L[i]/x);
	}
	return num >= K;
}

void solve(){
	double lb = 0, ub = INT_MAX;

	for(int i = 0; i < 100; i++){
		double mid = (lb+ub)/2;
		if (is_feasible(mid))
			lb = mid;
		else
			ub = mid;
	}

	printf("%.2f\n", floor(ub *100) /100);    //因为求的是最长的绳长，所以此处取up
}

int main(){
	//initial
	L[0] = 8.02;
	L[1] = 7.43;
	L[2] = 4.57;
	L[3] = 5.39;

	N = 4; 

	K = 11;

	solve();
}

