#include <bits/stdc++.h>

using namespace std;

int parent[300001];
bool visited[300001];

int n, l;

int find(int u){
	return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);
	parent[u] = v;
	return;
}

int main(){
	int first, second;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> l;
	iota(parent + 1, parent + l, 1);
	for(int i = 0; i < n; i++){
		cin >> first >> second;
		if(!visited[first]){
			visited[first] = true;
			merge(first, second);
			cout << "LADICA" << "\n";
		}
		else if(!visited[second]){
			visited[second] = true;
			merge(second, first);
			cout << "LADICA" << "\n";
		}
		else if(!visited[find(first)]){
			visited[find(first)] = true;
			merge(first, second);
			cout << "LADICA" << "\n";
		}
		else if(!visited[find(second)]){
			visited[find(second)] = true;
			merge(second, first);
			cout << "LADICA" << "\n";
		}
		else cout << "SMECE" << "\n";
	}
	return 0;
}