#include <bits/stdc++.h>

using namespace std;

int n;
int numlist[1001];
vector<int> num;

int main(){
	int x;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(!numlist[x])	num.push_back(x);
		numlist[x]++;
	}

	sort(num.begin(), num.end());
	
	int temp, k;
	bool check;
	
	for(int i = 0; i < num.size() - 1; i++){
		if(!numlist[num[i]])	continue;
		for(k = i + 1 ; k < num.size(); k++){
			if(num[k] == num[i] + 1 && numlist[num[k]]){
				break;
			}
		}
		if(k != num.size()){
			check = false;
			temp = 0;
			for(int j = i + 1; j < num.size(); j++){
				if(num[j] >= num[i] + 2 && numlist[num[j]] > 0){
					check = true;
					temp = j;
					break;
				}
			}
			if(check){
				while(numlist[num[i]] > 0){
					cout << num[i] << " ";
					numlist[num[i]]--;
				}
				numlist[num[temp]]--;
				cout << num[temp] << " ";
			}
			else{
				while(numlist[num[k]] > 0){
					cout << num[k] << " ";
					numlist[num[k]]--;
				}
				while(numlist[num[i]] > 0){
					cout << num[i] << " ";
					numlist[num[i]]--;
				}
			}
		}
		else{
			while(numlist[num[i]]--){
				cout << num[i] << " ";
			}
		}
	}
	while(numlist[num[num.size() - 1]] > 0){
			//cout << "test" << " ";
		cout << num[num.size() - 1] << " ";
		numlist[num[num.size() - 1]]--;
	}
	
	return 0;
}