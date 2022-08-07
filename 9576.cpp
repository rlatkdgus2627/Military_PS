#include <bits/stdc++.h>

using namespace std;

int t, n, m, ans;

vector<pair<int, int> > range;

bool visited[1001];

bool cmp(pair<int, int> &a, pair<int, int> &b){
	if(a.second == b.second)	return a.first < b.first;
	else return a.second < b.second;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		int s, e;
		ans = 0;
		range.clear();
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> s >> e;
			range.push_back(make_pair(s, e));
			
		}
		sort(range.begin(), range.end(), cmp);
		memset(visited, false, sizeof(visited));
		for(auto cur : range){
			for(int i = cur.first; i <= cur.second; i++){
				if(!visited[i]){
					visited[i] = true;
					ans++;
					break;
				}
			} 
		}
		cout << ans << "\n";
	}
	return 0;
}