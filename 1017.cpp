#include <bits/stdc++.h>

using namespace std;

int n;
int num[51];
int u[51], v[51];
vector<int> edges[51], ans;
bool visited[51];
bool isPrime[2000];

void findPrime(){
	for(int i = 2; i <= sqrt(1999); i++){
		if(isPrime[i])	continue;
		for(int j = i * 2; j <= 1999; j += i){
			isPrime[j] = true;
		}
	}
}

bool dfs(int cur){
	if(visited[cur])	return false;
	visited[cur] = true;
	for(int next : edges[cur]){
		if(!v[next] || dfs(v[next])){
			u[cur] = next;
			v[next] = cur;
			u[next] = cur;
			v[cur] = next;
			return true;
		}
	}
	return false;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int cnt;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	findPrime();
	for(int i = 1; i <= n - 1; i++){
		for(int j = i + 1; j <= n; j++){
			if(!isPrime[num[i] + num[j]]){
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
	
	for(int x : edges[1]){
		cnt = 1;
		memset(u, 0, sizeof(u));
		memset(v, 0, sizeof(v));
		u[1] = x;
		v[x] = 1;
		v[1] = x;
		u[x] = 1;
		for(int i = 1; i <= n; i++){
			if(!u[i]){
				memset(visited, false, sizeof(visited));
				visited[1] = true;
				visited[x] = true;
				if(dfs(i))	cnt++;
			}
		}
		if(cnt == n/2)	ans.push_back(num[x]);
	}
	if(!ans.size())	cout << "-1";
	else{
		sort(ans.begin(), ans.end());
		for(int x : ans)	cout << x << " ";
	}

	return 0;
}