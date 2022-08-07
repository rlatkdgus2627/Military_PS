#include <bits/stdc++.h>

using namespace std;

unordered_set<int> s;

int n, m, x;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> x;
		s.insert(x);
	}
	for(int i = 0; i < m; i++){
		cin >> x;
		if(s.find(x) != s.end()){
			s.erase(x);
		}
		else s.insert(x);
	}
	cout << s.size();
	return 0;
}