#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
string input;

pair<ll, int> cnt[10];
bool check[10];

ll ans;


int main(){
	ll p;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> input;
		check[input[0] - 'A'] = true;
		p = 1;
		for(int j = input.size() - 1; j >= 0; j--){
			cnt[input[j] - 'A'].first += p;
			p *= 10;
		}
	}
	for(int i = 0; i < 10; i++){
		cnt[i].second = i;
	}
	sort(cnt, cnt + 10);
	
	if(cnt[0].first != 0 && check[cnt[0].second]){
		int index;
		for(int i = 1; i < 10; i++){
			if(!check[cnt[i].second]){
				index = i;
				break;
			}
		}
		pair<ll, int> temp = cnt[index];
		for(int i = index - 1; i >= 0; i--) cnt[i+1] = cnt[i];
		cnt[0] = temp;
	}
	
	for(int i = 9; i >= 0; i--){
		if(cnt[i].first == 0)	break;
		ans += cnt[i].first * (ll)i;
	}
	
	cout << ans;
	
	return 0;
}