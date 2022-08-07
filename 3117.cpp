#include <bits/stdc++.h>

using namespace std;

int n, k, m;
int start[100001];
int rec[100001];
int table[100001][32];

void getTable(){
	for(int i = 1; i <= k; i++){
		table[i][0] = rec[i];
	}
	for(int i = 1; i < 32; i++){
        for(int j = 1; j <= k; j++){
            table[j][i] = table[table[j][i-1]][i-1];
        }
    }
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k >> m;
	m--;
	for(int i = 1; i <= n; i++){
		cin >> start[i];
	}
	for(int i = 1; i <= k; i++){
		cin >> rec[i];
	}
	getTable();
	int ans;
	for(int i = 1; i <= n; i++){
		ans = start[i];
		for(int j = 31; j >= 0; j--){
            if(m & (1 << j))    ans = table[ans][j];
        }
		cout << ans << " ";
	}
	return 0;
}