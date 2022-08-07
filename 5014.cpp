#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;
bool visited[1000001], check;
int ans;
int main(){
	cin >> F >> S >> G >> U >> D;
	queue<pair<int, int> >Q;
	visited[S] = true;
	Q.push(make_pair(S, 0));
	while(!Q.empty()){
		pair<int, int> cur = Q.front();
		Q.pop();
		if(cur.first == G){
			check = true;
			ans = cur.second;
			break;
		}
		if(cur.first + U <= F && !visited[cur.first + U]){
			visited[cur.first + U] = true;
			Q.push(make_pair(cur.first + U, cur.second + 1));
		}
		if(cur.first - D >= 1 && !visited[cur.first - D]){
			visited[cur.first - D] = true;
			Q.push(make_pair(cur.first - D, cur.second + 1));
		}
	}
	if(!check)	cout << "use the stairs";
	else cout << ans;
	return 0;
}