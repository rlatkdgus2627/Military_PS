#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;

char input[33][33];

ll coin[32], curState, nextState;
int ans, cur, nxt;
double T = 1.0, k = 4.0; 

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	srand(time(NULL));
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(input[i][j] == 'T')	coin[i] |= (1 << j);
		}
	}
	
	ans = cur = n * n;
	
	for(int i = 0; i < 10000; i++){
		
		int rd = rand() % n;
		
		nextState = curState ^ (1 << rd);
		
		nxt = 0;
		
		for(int j = 0; j < n; j++){
			nxt += min(__builtin_popcount(coin[j] ^ nextState), n - __builtin_popcount(coin[j] ^ nextState));
		}
		
		double p = exp((double)(cur - nxt)/(k * T));
		
		if(p > (double)rd / (double)(n - 1)){
			curState = nextState;
			cur = nxt;
		}

		ans = min(ans, cur);
		k *= 0.9999;
		
	}
	
	cout << ans;
}