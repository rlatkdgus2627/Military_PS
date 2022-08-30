#include <bits/stdc++.h>

using namespace std;

char cost[15][16];
int n;

int dp[16][10][1 << 16];

int solve(int cur, int price, int visited){
	if(visited == (1 << n) - 1)	return 0;
	int& ret = dp[cur][price][visited];
	if(ret)	return ret;
	ret = 1;
	for(int i = 1; i < n; i++){
		if(i == cur || (visited & (1 << i)) || price > cost[cur][i] - '0')	continue;
		ret = max(ret, solve(i, cost[cur][i] - '0', visited | (1 << i)) + 1);
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> cost[i];
	}
	cout << solve(0, 0, 0);
}
/*
13
9899998899898
9360626187920
2375922897361
2931947845036
1063206155476
5693745254744
3078688431492
0689266495048
7172722610615
9490917711597
7673656394812
9390885096385
6115984810304

answer : 8
my output : 10
*/