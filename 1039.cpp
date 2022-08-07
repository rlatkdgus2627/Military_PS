#include <bits/stdc++.h>

using namespace std;

string input, ans;

int k;
bool check;

map<pair<string, int>, bool>visited;


int main(){
	cin >> input >> k;
	queue<pair<string, int> >Q;
	Q.push(make_pair(input, 0));
	visited[make_pair(input, 0)] = true;
	
	ans = "0";
	
	while(!Q.empty()){
		pair<string, int> cur = Q.front();
		Q.pop();
		if(cur.second == k){
			check = true;
			if(cur.first.compare(ans) > 0){
				ans = cur.first;
			}
			continue;
		}
		if(cur.first.length() == 1)	continue;
		
		for(int i = 0; i < cur.first.length() - 1; i++){
			for(int j = i + 1; j < cur.first.length(); j++){
				if(i == 0 && cur.first[j] == '0'){
					continue;
				}
				string tempStr = cur.first;
				char temp = tempStr[i];
				tempStr[i] = tempStr[j];
				tempStr[j] = temp;
				if(!visited[make_pair(tempStr, cur.second + 1)]){
                    visited[make_pair(tempStr, cur.second + 1)] = true;
					Q.push(make_pair(tempStr, cur.second + 1));
				}
			}
		}
	}
	
	if(!check){
		cout << "-1";
	}
	else{
		cout << ans;
	}
	
	return 0;
}