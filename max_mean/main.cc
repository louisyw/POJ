/*
 *有n个物品的重量和价值分别是Wi和vi。从中选出k个物品使得单位重量的价值最大
 */

#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAX_N = 10000;
int n, k;
int w[MAX_N]= {2,5,2};
int v[MAX_N]= {2,3,1};
double y[MAX_N];

bool is_feasible(double d){
	for(int i = 0; i < n; i++)
		y[i] = v[i] - d*w[i];

	
	sort(y, y + n);

	double sum = 0;
	/*此处判断平均价值,只用保证sum >= 0(想想为什么)，结果为0.75*/
	for(int i = 0; i < k; i++){
		sum += y[n- i - 1];
	}

	return sum>=0;
	
	/*此种方法不对，对于此题，得到的结果为0.6
	int m = lower_bound(y, y+n, 0) -y;
	return m <= n-k;
	*/
}

void solve(){
	double lb = 0; 
	double ub = INT_MAX;

	for(int i = 0; i < 100; i++){
		double mid = (lb+ub)/2;

		if (is_feasible(mid))
			lb = mid;
		else
			ub = mid;
	}

	printf("%.2f\n", ub);
}


int main(){
	n=3;
	k=2;

	solve();
	return 0;	n=3;
	k=2;

	solve();
	return 0;	n=3;
	k=2;

	solve();
	return 0;

}
