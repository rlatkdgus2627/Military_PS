#include <bits/stdc++.h>

using namespace std;

int n;

int f[1000001];
int num[1000001];
int ans[1000001];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
		f[num[i]]++;
	}
	
	stack<int> S;
	
	for(int i = n; i >= 1; i--){
		while(!S.empty() && f[S.top()] <= f[num[i]])	S.pop();
		if(S.empty())	ans[i] = -1;
		else ans[i] = S.top();
		S.push(num[i]);
	}
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}