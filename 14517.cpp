#include <bits/stdc++.h>

using namespace std;

string input;

int n, ans;
bool palindrome[1005][1005];

int main(){
    cin >> input;
    n = input.size();
    input = " " + input;

    for(int i = 1; i <= n; i++){
        palindrome[i][i] = true;
    }

    for(int i = 1; i <= n - 1; i++){
        if(input[i] == input[i+1])  palindrome[i][i + 1] = true;
    }

    for(int i = 2; i <= n - 1; i++){
        for(int j = 1; j + i <= n; j++){
            if(input[j] == input[j + i] && palindrome[j + 1][j + i - 1]){
                palindrome[j][j + i] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			ans += palindrome[i][j];
		}
	}
	cout << ans % 10007 << "\n";

    return 0;

}