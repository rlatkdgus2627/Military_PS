#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct query{
	int index, s, e;
};

int n, t;
int sqrtN;
ll num[100001];
ll ans[100001];
ll cnt[1000001];
ll sum;

vector<query> v;

bool cmp(query &lhs, query &rhs){
	if(lhs.s / sqrtN == rhs.s / sqrtN)	return lhs.e < rhs.e;
	else return lhs.s / sqrtN < rhs.s / sqrtN;
}

int main(){
	int s, e;
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> t;
	
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	
	for(int i = 0; i < t; i++){
		cin >> s >> e;
		v.push_back({i, s, e});
	}
	
	sqrtN = sqrt(n);
	
	sort(v.begin(), v.end(), cmp);
	
	s = v[0].s;
	e = v[0].e;
	
	for(int i = s; i <= e; i++){
		sum += (2 * cnt[num[i]] + 1) * num[i];
		cnt[num[i]]++;
	}
	
	ans[v[0].index] = sum;
	
	for(int i = 1; i < t; i++){
		while(s < v[i].s){
			sum -= (2 * cnt[num[s]] - 1) * num[s];
			cnt[num[s]]--;
			s++;
		}
		
		while(v[i].s < s){
			s--;
			sum += (2 * cnt[num[s]] + 1) * num[s];
			cnt[num[s]]++;
		}
		
		while(e < v[i].e){
			e++;
			sum += (2 * cnt[num[e]] + 1) * num[e];
			cnt[num[e]]++;
		}
		
		while(v[i].e < e){
			sum -= (2 * cnt[num[e]] - 1) * num[e];
			cnt[num[e]]--;
			e--;
		}
		
		ans[v[i].index] = sum;
	}
	
	for(int i = 0; i < t; i++) 
		cout << ans[i] << "\n";
	
	return 0;
}