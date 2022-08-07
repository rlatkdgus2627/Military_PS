#include <bits/stdc++.h>

using namespace std;

map<string, int> num;
string names[100001];

int n, m;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	string input;
	for(int i = 1; i <= n; i++){
		cin >> input;
		names[i] = input;
		num[input] = i;
	}
	for(int i = 0; i < m; i++){
		cin >> input;
		if(('a' <= input[0] && input[0] <= 'z') || ('A' <= input[0] && input[0] <= 'Z')){
			cout << num[input] << "\n";
		}
		else{
			cout << names[stoi(input)] << "\n";
		}
	}
	return 0;
}