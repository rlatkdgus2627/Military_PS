#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int v, e, cnt;

int parent[50001], Rank[50001];

vector<pair<int, ll> >graph[100001];


bool visited[50001];
ll depth[50001];
ll table[50001][21];
ll maxtable[50001][21];
ll total;

struct edge{
    int s, e;
    ll weight;
};

bool cmp(edge& lhs, edge& rhs){
    return lhs.weight < rhs.weight;
}

int find(int u){
    if(u == parent[u])  return u;
    return parent[u] = find(parent[u]);
}

void merge(int x, int y){
    int temp;
    x = find(x);
    y = find(y);
    if(Rank[x] == Rank[y])  Rank[x]++;
    else if(Rank[x] < Rank[y]){
        temp = x;
        x = y;
        y = temp;
    }
    parent[x] = y;
    cnt--;
}

void dfs(int cur, int d){
    visited[cur] = true;
    depth[cur] = d;
    for(auto next:graph[cur]){
        if(!visited[next.first]){
            table[next.first][0] = cur;
            maxtable[next.first][0] = next.second;
            dfs(next.first,d+1);
        }
    }
}

void getTable(){
    for(int j = 1; j <= 20; j++){
        for(int i = 1; i <= v; i++){
            table[i][j] = table[table[i][j-1]][j-1];
            maxtable[i][j] = max(maxtable[i][j-1], maxtable[table[i][j-1]][j-1]);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<edge> edges;
    vector<edge> useless;

    int x, y, temp;
    ll w, ans = 1e18;

    cin >> v >> e;
    iota(parent + 1, parent + 1 + v, 1);

    cnt = v - 1;

    for(int i = 0; i < e; i++){
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    sort(edges.begin(), edges.end(), cmp);

    for(auto data : edges){
        if(find(data.s) != find(data.e) && cnt){
            merge(data.s, data.e);
            graph[data.s].push_back(make_pair(data.e, data.weight));
            graph[data.e].push_back(make_pair(data.s, data.weight));
            total += data.weight;
        }
        else{
            useless.push_back(data);
        }
    }

    if(cnt || !useless.size()){
        cout << "-1";
		return 0;
    }

    dfs(1, 0);
    getTable();

    for(auto data : useless){
        ll maxans = 0;
        x = data.s;
        y = data.e;
        if(depth[x] < depth[y]){
            temp = x;
            x = y;
            y = temp;
        }
        for(int j = 20; j>= 0; j--){
            if(depth[x] - depth[y] >= (1<<j)){
                maxans = max(maxans, maxtable[x][j]);
                x = table[x][j];
            }

        }
        if(x != y){
            for(int j = 20; j>= 0; j--){
                if(table[x][j] != table[y][j]){
                    if(table[x][j] != table[y][j]){
                        maxans = max(maxans, max(maxtable[x][j], maxtable[y][j]));
                        x = table[x][j];
                        y = table[y][j];
                    }
                }
            }
            maxans = max(maxans, max(maxtable[x][0], maxtable[y][0]));
        }
		if(ans > total - maxans + data.weight)	ans = total - maxans + data.weight;
    }
    cout << (ans == total || ans == 1e18 ? -1 : ans);

    return 0;
}