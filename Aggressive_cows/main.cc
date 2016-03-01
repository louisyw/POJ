/*
 *Aggressive Cows (POJ 2456)
 */
#include <cstdio>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MAX_N = 100000;
int N, M;
int x[MAX_N];

bool is_feasible(int d){
	int last = 0;
	for (int i = 1; i < M; i++){    //注意此处从1开始，因为第一头牛已经放在x[0]处
		int crt = last + 1;

		while(crt < N && x[crt] - x[last] < d){  //此处为<d(改为<=d会如何)
			crt++;
		}

		if (crt == N)  return false;
		last = crt;
	}
	return true;
}

void solve(){
	
	sort(x, x + N);
	
	int lb = 0; 
	int ub = INT_MAX;
	int mid;
	while(ub - lb > 1){
		mid = (lb+ub)/2;
		if (is_feasible(mid))
			lb = mid;
		else
			ub = mid;
	}

	printf("%d\n",lb);
	printf("%d\n",ub);
	printf("%d\n",mid);
}

int main(){
	scanf("%d", &N);
	scanf("%d", &M);
	
	int i = 0;
	while(i < N){
		scanf("%d" ,x+i);
		++i;
	}

	/*M = 3; 
	N=5;*/
	solve();
	return 0;
}
