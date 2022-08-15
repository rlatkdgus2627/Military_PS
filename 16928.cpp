#include <bits/stdc++.h>

using namespace std;

int n, m;

int ladder[101], snake[101];

bool visited[101];

bool safe(int cur){
	return 1 <= cur && cur <= 100;
}
int main(){
	int s, e;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s >> e;
		ladder[s] = e;
	}
	for(int i = 0; i < m; i++){
		cin >> s >> e;
		snake[s] = e;
	}
	
	queue<pair<int, int> > Q;
	Q.push(make_pair(1, 0));
	visited[1] = true;
	while(!Q.empty()){
		pair<int, int> cur = Q.front();
		Q.pop();
		if(cur.first == 100){
			cout << cur.second << "\n";
			break;
		}
		for(int i = 1; i <= 6; i++){
			if(safe(cur.first + i) && snake[cur.first + i] && !visited[snake[cur.first + i]]){
				visited[snake[cur.first + i]] = true;
				Q.push(make_pair(snake[cur.first + i], cur.second + 1));
			}
			else if(safe(cur.first + i) && ladder[cur.first + i] && !visited[ladder[cur.first + i]]){
				visited[ladder[cur.first + i]] = true;
				Q.push(make_pair(ladder[cur.first + i], cur.second + 1));
			}
			else if(safe(cur.first + i) && !visited[cur.first + i]){
				visited[cur.first + i] = true;
				Q.push(make_pair(cur.first + i, cur.second + 1));
			}
		}
	}
	return 0;
}