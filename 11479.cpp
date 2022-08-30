#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string input;

ll n;
ll t;

vector<ll>suffix, cur, nextGroup, lcp, revSuffix;

bool cmp(const ll &a, const ll &b){
	if(cur[a] == cur[b])	return cur[a + t] < cur[b + t];
	else return cur[a] < cur[b];
}

void getSuffix(){
	suffix.resize(n);
	cur.resize(n + 1);
	nextGroup.resize(n + 1);
	for(ll i = 0; i < n; i++){
		suffix[i] = i;
		cur[i] = input[i] - 'a';
	}
	cur[n] = -1;
	for(t = 1; t <= n; t <<= 1){
		sort(suffix.begin(), suffix.end(), cmp);
		nextGroup[n] = -1;
		nextGroup[suffix[0]] = 0;
		for(ll i = 1; i < n; i++){
			if(cmp(suffix[i - 1], suffix[i]))	nextGroup[suffix[i]] = nextGroup[suffix[i - 1]] + 1;
			else nextGroup[suffix[i]] = nextGroup[suffix[i - 1]];
		}
		for(ll i = 0; i < n; i++){
			cur[i] = nextGroup[i];
		}
	}
}

void getLcp(){
	ll k = 0;
	lcp.resize(n + 1);
	revSuffix.resize(n + 1);
	for(ll i = 0; i < n; i++){
		revSuffix[suffix[i]] = i;
	}
	
	for(ll i = 0; i < n; i++){
		if(revSuffix[i]){
			ll j = suffix[revSuffix[i] - 1];
			while(input[i + k] == input[j + k])	k++;
			lcp[revSuffix[i]] = k;
			if(k)	k--;
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> input;
	n = input.size();
	getSuffix();
	getLcp();
	cout << n * (n + 1)/2 - accumulate(lcp.begin(), lcp.end(), 0LL);
	return 0;
}