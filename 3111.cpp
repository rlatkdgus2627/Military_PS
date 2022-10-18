#include <bits/stdc++.h>

using namespace std;

string A, T, ans;

deque<char> dq1, dq2;

int main(){
	int temp;
	bool check;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> A;
	cin >> T;

	int s = 0, e = T.size() - 1;
	while(s <= e){
		while(s <= e){
			dq1.push_back(T[s++]);
			if(dq1.size() >= A.size()){
				temp = dq1.size() - A.size();
				check = true;
				for(int i = 0; i < A.size(); i++){
					if(dq1[temp + i] != A[i]){
						check = false;
						break;
					}
				}
				if(check){
					temp = A.size();
					while(temp--){
						dq1.pop_back();
					}
					break;
				}
			}
		}
		while(s <= e){
			dq2.push_front(T[e--]);
			if(dq2.size() >= A.size()){
				check = true;
				for(int i = 0; i < A.size(); i++){
					if(dq2[i] != A[i]){
						check = false;
						break;
					}
				}
				if(check){
					temp = A.size();
					while(temp--){
						dq2.pop_front();
					}
					break;
				}
			}
		}
	}
	
	for(int i = 0; i < dq1.size(); i++){
		ans += dq1[i];
	}
	for(int i = 0; i < dq2.size(); i++){
		ans += dq2[i];
	}
	
	while(ans.find(A) != string::npos){
		ans.erase(ans.find(A), A.size());
	}
	
	cout << ans;
	return 0;
}