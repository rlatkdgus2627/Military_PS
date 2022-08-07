#include <bits/stdc++.h>

using namespace std;

char input[9];
char Boggle[4][5];
int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
unordered_set<string> findWord;

bool visited[4][4];

int w, ans, b, maxlen;
string ansString;

int char_to_index(char c){
	return c - 'A';
}

bool safe(int x, int y){
	return (0 <= x && x < 4) && (0 <= y && y < 4);
}

struct Trie{
	bool is_leaf;
	Trie* next[26];
	Trie():is_leaf(false){
		memset(next, 0, sizeof(next));
	}
	~Trie(){
		for(int i = 0; i < 26; i++){
			if(next[i])	delete next[i];
		}
	}
	void insert(char *key){
		if(*key == '\0'){
			is_leaf = true;
			return;
		}
		int index = char_to_index(*key);
		if(!next[index]){
			next[index] = new Trie();
		}
		if(next[index])	next[index]->insert(key + 1);
	}
	
	void dfs(int x, int y, string cur){
		if(cur.length() > 8)	return;
		int index = char_to_index(Boggle[x][y]);
		bool check = false;
		visited[x][y] = true;
		cur += Boggle[x][y];
		if(!next[index]){
			visited[x][y] = false;
			return;
		}
		if(next[index] -> is_leaf){
			findWord.insert(cur);
		}
		for(int i = 0; i < 8; i++){
			if(safe(x + dx[i], y + dy[i]) && !visited[x + dx[i]][y + dy[i]]){
				next[index]->dfs(x + dx[i], y + dy[i], cur);
			}
		}
		visited[x][y] = false;
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> w;
	Trie* root = new Trie();
	for(int i = 0; i < w; i++){
		cin >> input;
		root->insert(input);
	}
	
	cin >> b;
	while(b--){
		findWord.clear();
		string ansString = "";
		ans = maxlen = 0;
		for(int i = 0; i < 4; i++){
			cin >> Boggle[i];
		}
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				root->dfs(i, j, "");
			}
		}
		for(auto x : findWord){
			ans += score[x.length()];
			if(maxlen < x.length()){
				maxlen = x.length();
				ansString = x;
			}
			if(maxlen == x.length() && ansString.compare(x) > 0){
				ansString = x;
			}
		}
		cout << ans << " " << ansString << " " << findWord.size() << "\n";
	}
	return 0;
}