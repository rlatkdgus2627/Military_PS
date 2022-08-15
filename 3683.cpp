#include <bits/stdc++.h>

using namespace std;

int t;
int c, d, v, ans;

vector<int>graph[501];
int cat[501], dog[501];
bool visited[501];

pair<string, string> vote[501];

void init(){
	memset(cat, 0, sizeof(cat));
	memset(dog, 0, sizeof(dog));
	ans = 0;
	for(int i = 0; i < 501; i++){
		graph[i].clear();
	}
}

bool dfs(int cur){
	if(visited[cur])	return false;
	visited[cur] = true;
	for(int next : graph[cur]){
		if(!dog[next] || dfs(dog[next])){
			dog[next] = cur;
			cat[cur] = next;
			return true;
		}
	}
	return false;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	string animal1, animal2;
	
	cin >> t;
	while(t--){
		init();
		cin >> c >> d >> v;
		for(int i = 1; i <= v; i++){
			cin >> animal1 >> animal2;
			vote[i] = make_pair(animal1, animal2);
		}
		
		for(int i = 1; i <= v - 1; i++){
			for(int j = i + 1; j <= v; j++){
				if(vote[i].first.compare(vote[j].second) == 0 || vote[j].first.compare(vote[i].second) == 0){
					if(vote[i].first[0] == 'C')	graph[i].push_back(j);
					else graph[j].push_back(i);
				}
			}
		}
		
		for(int i = 1; i <= v; i++){
			if(!cat[i]){
				memset(visited, 0, sizeof(visited));
				if(dfs(i))	ans++;
			}
		}
		cout << v - ans << "\n";
	}
	return 0;
}