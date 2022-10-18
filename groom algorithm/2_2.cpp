#include <bits/stdc++.h>
using namespace std;
int ans = 1, n;
string input;
char cur;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> input;
	cur = input[0];
	for(int i = 1; i < n; i++){
		if(cur != input[i]){
			ans++;
			cur = input[i];
		}
	}
	cout << ans;
	return 0;
}