#include <bits/stdc++.h>

using namespace std;

vector<int>graph[503];
int n;
int flow[503][503], capacity[503][503], group[501];

const int INF = 1e9;
const int BIG = 5e5;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> group[i];
	}
	
	int u, v, x;
	
	for(int i = 0; i < 503; i++){
		fill(capacity[i], capacity[i] + 503, INF);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> x;
			if(i >= j)	continue;
			if(group[i] == group[j] && group[i]){
				capacity[i][j] = BIG;
			}
			else capacity[i][j] = x;
			
			graph[i].push_back(j);
			graph[j].push_back(i);
		}
	}
	
	
	return 0;
}