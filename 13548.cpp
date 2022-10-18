#include <bits/stdc++.h>

using namespace std;

struct query{
	int index, s, e;
};

int n, m, sqrtN;

vector<query> v;

int ans[100001], num[100001];
int check[1000001], cnt[100001], maxValue;

bool cmp(query &lhs, query &rhs){
	if(lhs.s/sqrtN == rhs.s/sqrtN)	return lhs.e < rhs.e;
	else return lhs.s/sqrtN < rhs.s/sqrtN;
}

int main(){
	int s, e;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	sqrtN = sqrt(n);
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> s >> e;
		v.push_back({i, s, e});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	s = v[0].s;
	e = v[0].e;
	
	for(int i = s; i <= e; i++){
		if(cnt[check[num[i]]])	cnt[check[num[i]]]--;
		check[num[i]]++;
		cnt[check[num[i]]]++;
		maxValue = max(maxValue, check[num[i]]);
	}
	ans[v[0].index] = maxValue;
	
	for(int i = 1; i < m; i++){
		
		while(s < v[i].s){
			if(cnt[check[num[s]]] == 1 && check[num[s]] == maxValue){
				maxValue--;
			}
			cnt[check[num[s]]]--;
			check[num[s]]--;
			cnt[check[num[s]]]++;
			s++;
		}
		
		while(v[i].s < s){
			s--;
			if(cnt[check[num[s]]])	cnt[check[num[s]]]--;
			check[num[s]]++;
			cnt[check[num[s]]]++;
			maxValue = max(maxValue, check[num[s]]);
		}
		
		while(e < v[i].e){
			e++;
			if(cnt[check[num[e]]])	cnt[check[num[e]]]--;
			check[num[e]]++;
			cnt[check[num[e]]]++;
			maxValue = max(maxValue, check[num[e]]);
		}
		
		while(v[i].e < e){                                                                             
			if(cnt[check[num[e]]] == 1 && check[num[e]] == maxValue){
				maxValue--;
			}
			cnt[check[num[e]]]--;
			check[num[e]]--;
			cnt[check[num[e]]]++;
			e--;
		}
		
		ans[v[i].index] = maxValue;
	}
	
	for(int i = 0; i < m; i++) 
		cout << ans[i] << "\n";
	
	return 0;
}