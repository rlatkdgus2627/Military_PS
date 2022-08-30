#include <bits/stdc++.h>

using namespace std;

string input;

int n;
int t;

vector<int>suffix, cur, nextGroup, lcp, revSuffix;

bool cmp(const int &a, const int &b){
	if(cur[a] == cur[b])	return cur[a + t] < cur[b + t];
	else return cur[a] < cur[b];
}

void getSuffix(){
	suffix.resize(n);
	cur.resize(n + 1);
	nextGroup.resize(n + 1);
	for(int i = 0; i < n; i++){
		suffix[i] = i;
		cur[i] = input[i] - 'a';
	}
	cur[n] = -1;
	for(t = 1; t <= n; t <<= 1){
		sort(suffix.begin(), suffix.end(), cmp);
		nextGroup[n] = -1;
		nextGroup[suffix[0]] = 0;
		for(int i = 1; i < n; i++){
			if(cmp(suffix[i - 1], suffix[i]))	nextGroup[suffix[i]] = nextGroup[suffix[i - 1]] + 1;
			else nextGroup[suffix[i]] = nextGroup[suffix[i - 1]];
		}
		for(int i = 0; i < n; i++){
			cur[i] = nextGroup[i];
		}
	}
}

void getLcp(){
	int k = 0;
	lcp.resize(n + 1);
	revSuffix.resize(n + 1);
	for(int i = 0; i < n; i++){
		revSuffix[suffix[i]] = i;
	}
	
	for(int i = 0; i < n; i++){
		if(revSuffix[i]){
			int j = suffix[revSuffix[i] - 1];
			while(input[i + k] == input[j + k])	k++;
			lcp[revSuffix[i]] = k;
			if(k)	k--;
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> input;
	getSuffix();
	getLcp();
	cout << *max_element(lcp.begin(), lcp.end());
	return 0;
}