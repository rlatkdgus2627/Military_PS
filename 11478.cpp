#include <bits/stdc++.h>

using namespace std;

set<string>s;
string input;

int main(){
	cin >> input;
	for(int i = 0; i < input.size(); i++){
		for(int j = 1; j <= input.size(); j++){
			s.insert(input.substr(i, j));
		}
	}
	cout << s.size();
	return 0;
}