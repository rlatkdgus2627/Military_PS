#include <bits/stdc++.h>
using namespace std;

int n, k;
int a, b, ans;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	while(k--){
		cin >> a >> b;
		for(int i = 0; i < 5; i++){
			if(a + dx[i] < 1 || a + dx[i] > n || b + dy[i] < 1 || b + dy[i] > n)	continue;
			ans++;
		}
	}
	cout << ans;
	return 0;
}