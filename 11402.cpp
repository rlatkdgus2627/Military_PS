#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll combination[2001][2001];

ll n, k, m;
ll ans = 1;

int main(){
	cin >> n >> k >> m;
	for(int i = 0; i <= 2000; i++){
		combination[i][0] = combination[i][i] = 1;
	}
	for(int i = 2; i <= 2000; i++){
		for(int j = 1; j <= i; j++){
			combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
			combination[i][j] %= m;
		}
	}
	while(n > 0 || k > 0){
		ll ni = n % m;
		ll ki = k % m;
		
		ans *= combination[ni][ki];
		ans %= m;
		
		n /= m;
		k /= m;
	}
	
	cout << ans;
	
}