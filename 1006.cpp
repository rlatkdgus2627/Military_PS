#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int t;
int n, w;
int enemy[10002][2], ans;
int dp[10002][3];

void solve(){
	int up, down, vertical;
	for(int i = 2; i <= n; i++){
		up = (enemy[i - 1][0] + enemy[i][0] > w ? 2 : 1);
		down = (enemy[i - 1][1] + enemy[i][1] > w ? 2 : 1);
		vertical = (enemy[i][0] + enemy[i][1] > w ? 2 : 1);
		
		dp[i][0] = dp[i - 1][0] + vertical;
		dp[i][0] = min(dp[i][0], dp[i - 2][0] + up + down);
		dp[i][0] = min(dp[i][0], dp[i - 1][1] + down + 1);
		dp[i][0] = min(dp[i][0], dp[i - 1][2] + up + 1);
		
		dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][2] + up);
		
		dp[i][2] = min(dp[i - 1][0] + 1, dp[i - 1][1] + down);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		int temp;
		ans = INF;
		cin >> n >> w;
		for(int i = 1; i <= n; i++){
			cin >> enemy[i][0];
		}
		for(int i = 1; i <= n; i++){
			cin >> enemy[i][1];
		}
		
		if(n == 1){
			cout << (enemy[1][0] + enemy[1][1] > w ? 2 : 1) << "\n";
			continue;
		}
		
		memset(dp, 0, sizeof(dp));
		dp[1][0] = (enemy[1][0] + enemy[1][1] > w ? 2 : 1);
		dp[1][1] = dp[1][2] = 1;
		solve();
		ans = min(ans, dp[n][0]);
		
		if(enemy[n][0] + enemy[1][0] <= w){
			memset(dp, 0, sizeof(dp));
			temp = enemy[1][0];
			enemy[1][0] = INF;
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			solve();
			ans = min(ans, dp[n][2]);
			enemy[1][0] = temp;
		}
		
		if(enemy[n][1] + enemy[1][1] <= w){
			memset(dp, 0, sizeof(dp));
			temp = enemy[1][1];
			enemy[1][1] = INF;
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			solve();
			ans = min(ans, dp[n][1]);
			enemy[1][1] = temp;
		}
		
		if(enemy[n][0] + enemy[1][0] <= w && enemy[n][1] + enemy[1][1] <= w){
			memset(dp, 0, sizeof(dp));
			enemy[1][0] = enemy[1][1] = INF;
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			solve();
			ans = min(ans, dp[n - 1][0]);
		}
		
		cout << ans << "\n";
		
	}
	return 0;
}