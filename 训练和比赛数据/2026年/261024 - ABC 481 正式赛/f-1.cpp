#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        mp[u].push_back({v, c});
    }

    const ll INF = 1LL << 60;
    const ll MOD = 998244353;
    
    vector<ll> dis(n + 1, INF);
    vector<bool> vis(n + 1, 0);

    queue<vector<int>> q;
    q.push({1});
    vis[1] = 1;
    dis[1] = 0;

    while (!q.empty()) {
        vector<int> V = q.front(); q.pop();

        vector<vector<int>> next_node(10);
        for (int& u: V) {
            for (auto& [v, c]: mp[u]) {
                if (!vis[v])
                    next_node[c].push_back(v);
            }
        }

        for (int c = 1; c <= 9; c++) {
            if (next_node[c].empty()) continue;

            vector<int> next_V;
            for (int& v: next_node[c]) {
                if (vis[v]) continue;
                vis[v] = 1;
                dis[v] = mod(dis[V[0]] * 10LL + c, MOD);
                next_V.push_back(v);
            }
            if (!next_V.empty()) q.push(next_V);
        }
    }
    for (int i = 2; i <= n; i++)
        cout << dis[i] << (i < n ? "\n" : "");
    return 0;
}