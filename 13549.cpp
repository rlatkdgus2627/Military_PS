#include <bits/stdc++.h>

using namespace std;

int n, k;

int ans;

bool visited[100001];

bool safe(int x){
	return 0 <= x && x <= 100000;
}

int main(){
	cin >> n >> k;
	deque<pair<int, int> > dq;
	dq.push_back(make_pair(n, 0));
	visited[n] = true;
	
	while(!dq.empty()){
		pair<int, int> cur = dq.front();
		dq.pop_front();
		
		if(cur.first == k){
			ans = cur.second;
			break;
		}
		
		if(safe(cur.first << 1) && !visited[cur.first << 1]){
			dq.push_front(make_pair(cur.first << 1, cur.second));
			visited[cur.first << 1] = true;
		}
		
		if(safe(cur.first + 1) && !visited[cur.first + 1]){
			dq.push_back(make_pair(cur.first + 1, cur.second + 1));
			visited[cur.first + 1] = true;
		}
		
		if(safe(cur.first - 1) && !visited[cur.first - 1]){
			dq.push_back(make_pair(cur.first - 1, cur.second + 1));
			visited[cur.first - 1] = true;
		}
	}
	
	cout << ans;
	
	
	return 0;
}