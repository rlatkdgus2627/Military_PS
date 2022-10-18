#include <bits/stdc++.h>

using namespace std;

int n;

char input[21][21];

int coin[21], ans, temp;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(input[i][j] == 'T')	coin[i] |= (1 << j);
		}
	}
	
	ans = n * n;
	
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			coin[j] ^= i;
		}
		
		temp = 0;
		
		for(int j = 0; j < n; j++){
			temp += min(__builtin_popcount(coin[j]), n - __builtin_popcount(coin[j]));
		}
		
		ans = min(ans, temp);
		
		for(int j = 0; j < n; j++){
			coin[j] ^= i;
		}
	}
	
	cout << ans;
}