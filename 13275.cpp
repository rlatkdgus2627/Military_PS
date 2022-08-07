#include <bits/stdc++.h>

using namespace std;

int n, ans, r, p;

string input, temp;
int A[200004];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> input;
	n = input.size();
	temp = " ";
	for(int i = 0; i < n; i++){
		temp += input[i];
		temp += " ";
	}
	input = temp;
	n = input.size();
	for(int i = 0; i < n; i++){
		if(i <= r)	A[i] = min(r - i, A[2 * p - i]);
		while(i + A[i] + 1 < n && i - A[i] - 1 >= 0 && input[i + A[i] + 1] == input[i - A[i] - 1])	A[i]++;
		if(r < i + A[i]){
			r = i + A[i];
			p = i;
		}
	}
	for(int i = 1; i <= n; i++){
		ans = max(ans, A[i]);
	}
	cout << ans;
	return 0;
}