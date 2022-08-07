#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll d, p, q, ans = 1e10;
ll temp;

int main(){
	cin >> d >> p >> q;
	if(p < q){
		temp = q;
		q = p;
		p = temp;
	}
	if(q == 1){
		cout << d;
		return 0;
	}
	if(d <= q){
		cout << p;
		return 0;
	}
	for(int i = d / (p + 1); i >= 0 ; i--){
		
	}
	return 0;
}