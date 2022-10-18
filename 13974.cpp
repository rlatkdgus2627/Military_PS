#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, n;
ll dp[5001][5001], psum[5001];
int opt[5001][5001];


int main(){
	ll x;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				opt[i][j] = dp[i][j] = psum[i] = 0;
			}
		}
		
		for(int i = 1; i <= n; i++){
			cin >> x;
			psum[i] = psum[i - 1] + x;
			opt[i - 1][i] = i;
		}
		
		for(int i = 2; i <= n; i++){
			for(int s = 0; s + i <= n; s++){
				int e = s + i;
				dp[s][e] = 1e18;
				for(int k = opt[s][e - 1]; k <= opt[s + 1][e]; k++){
					ll temp = dp[s][k] + dp[k][e] + psum[e] - psum[s]; 
					if(dp[s][e] > temp){
						dp[s][e] = temp;
						opt[s][e] = k;
					}
				}
			}
		}
		cout << dp[0][n] << "\n";
	}
	
	return 0;
}