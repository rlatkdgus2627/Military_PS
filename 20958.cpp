#include <bits/stdc++.h>

using namespace std;

int n, m;

int num[50001], arr[50001], maxValue, ans, cnt, remain, divided;
bool check;

bool isPrime[10000001];
vector<int>	prime;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> num[i];
		if(num[i] % 7 || num[i] % 49 == 0)	check = true;
		num[i] /= 7;
		maxValue = max(maxValue, num[i]);
	}
	
	if(check){
		cout << "-1";
		return 0;
	}
	
	isPrime[1] = true;
	
	for(int i = 2; i <= sqrt(maxValue); i++){
		if(isPrime[i])	continue;
		for(int j = i * 2; j <= maxValue; j += i){
			isPrime[j] = true;
		}
	}
	for(int i = 2; i <= maxValue; i++){
		if(!isPrime[i])	prime.push_back(i);
	}
	
	for(auto p : prime){
		if(p > sqrt(maxValue))	break;
		fill(arr, arr + n + 1, 0);
		divided = 0;
		for(int i = 1; i <= n; i++){
			cnt = 0;
			while(num[i] % p == 0){
				num[i] /= p;
				cnt++;
			}
			if(cnt > divided){
				ans += cnt - divided;
				if(i + m - 1 <= n)	arr[i + m - 1] = cnt - divided;
				divided = cnt;
			}
			divided -= arr[i];
		}
	}
	
	fill(arr, arr + n + 1, 0);
	
	set<int> s;
	s.insert(1);
	
	for(int i = 1; i <= n; i++){
		
		if(s.find(num[i]) == s.end()){
			ans++;
			s.insert(num[i]);
			if(i + m - 1 <= n)	arr[i + m - 1] = num[i];
		}
		if(arr[i])	s.erase(arr[i]);
	}
	
	cout << ans;
	
	return 0;
}