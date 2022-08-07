#include <bits/stdc++.h>

using namespace std;

int n;

int num[100001];
int dp[201][100001];

int ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	if(n == 1){
		cout << "1";
		return 0;
	}
	
	
	
	cout << ans;
	
	return 0;
}