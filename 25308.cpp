#include <bits/stdc++.h>

using namespace std;

vector<double> num(8), p(8), temp(8);

pair<double, double> code[8];

int ans;
bool visited[8];

int ccw(pair<double, double> &a,pair<double, double> &b, pair<double, double> &c){
	double temp = a.first * b.second + b.first * c.second + c.first * a.second;
	temp -= a.second * b.first + b.second * c.first + c.second * a.first;
	if(temp > 0)	return 1;
	else if(temp < 0)	return -1;
	else return 0;
}

bool solve(){
	double pi = acos(-1);
	for(int i = 0; i < 8; i++){
		code[i].first = num[i] * cos(45.0 * (double)i * pi/180.0);
		code[i].second = num[i] * sin(45.0 * (double)i * pi/180.0);
	}
	for(int i = 0; i < 6; i++){
		if(ccw(code[i], code[i + 1], code[i + 2]) < 0)	return false;
	}
	
	if(ccw(code[6], code[7], code[0]) < 0)	return false;
	if(ccw(code[7], code[0], code[1]) < 0)	return false;
	
	return true;
}

void make_permutation(int cur){
	if(cur == 8){
		for(int i = 0; i < 8; i++){
			num[i] = temp[i];
		}
		ans += solve();
	}
	for(int i = 0; i < 8; i++){
		if(!visited[i]){
			temp[cur] = p[i];
			visited[i] = true;
			make_permutation(cur + 1);
			visited[i] = false;
		}
	}
}

int main(){
	for(int i = 0; i < 8; i++){
		cin >> p[i];
	}
	
	make_permutation(0);
	
	cout << ans;
}