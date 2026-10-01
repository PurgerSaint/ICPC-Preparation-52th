#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

vector<vector<int>> mp;
vector<int> match;          // 匹配结果
vector<bool> vis;           // 访问标记

bool dfs(int u) {
    for (int& v: mp[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        // 不随访问标记行动，根据是否已经匹配行动
        if (match[v] == 0 || dfs(match[v])) {
            match[v] = u; return 1;
        }
    }
    return 0;
}

int main() {
    ios;
    int n, m, e; cin >> n >> m >> e;
    mp = vector<vector<int>>(n + 1);
    for (int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
    }
    match = vector<int>(m + 1);
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        vis = vector<bool>(m + 1, 0);
        if (dfs(u)) ans++;
    }
    cout << ans;
    return 0;
}