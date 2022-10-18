#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll r1, c1, r2, c2;

ll getAbs(ll num){
	if(num < 0)	return num * -1;
	else return num;
}

ll findNum(ll x, ll y){
	if(x == 0 && y == 0)	return 1;
	ll group = max(getAbs(x), getAbs(y));
	ll maxValue = (1 + 2 * group) * (1 + 2 * group);
	ll minValue = (1 + 2 * (group - 1)) * (1 + 2 * (group - 1));
	ll menhatan;
	menhatan = getAbs(x - group) + getAbs(y - group);
	if(x >= y)	return maxValue - menhatan;
	else	return minValue + menhatan;
}

int main(){
	ll MAX = 0;
	int interval = 0; 
	scanf("%lld %lld %lld %lld", &r1, &c1, &r2, &c2);
	for(ll i = r1; i <= r2; i++){
		for(ll j = c1; j <= c2; j++){
			MAX = max(MAX, findNum(i, j));
		}
	}
	while(MAX){
		MAX /= 10;
		interval++;
	}
	
	for(ll i = r1; i <= r2; i++){
		for(ll j = c1; j <= c2; j++){
			printf("%*lld ",interval, findNum(i, j));
		}
		printf("\n");
	}
	return 0;
}