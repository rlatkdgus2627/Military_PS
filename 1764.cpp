#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_set<string> lists;
vector<string> ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	string input;
	for(int i = 0; i < n; i++){
		cin >> input;
		lists.insert(input);
	}
	for(int i = 0; i < m; i++){
		cin >> input;
		if(lists.find(input) != lists.end()){
			ans.push_back(input);
		}
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(auto x : ans){
		cout << x << "\n";
	}
	
	return 0;
}