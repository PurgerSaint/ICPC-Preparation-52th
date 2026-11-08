#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

vector<vector<int>> dis;
vector<vector<int>> mp;
int ans = 0;
bool dfs(int u, const int& t) {
    if (u == t) return 1;
    for (int& v: mp[u]) {
        if (v == t) return 1;
        if (dis[2][v] >= dis[2][t] || dis[2][v] < dis[2][u]) continue;
        if (dfs(v, t)) {
            ans = max(ans, abs(dis[1][v] - dis[0][v]));
            return 1;
        }
    }
    return 0;
}

int main() {
    ios;
    int n, m, a, b, s, t; cin >> n >> m >> a >> b >> s >> t;
    mp = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dis = vector<vector<int>>(3, vector<int>(n + 1, 1LL << 30));
    
    vector<int> g;
    g.push_back(a);
    g.push_back(b);
    g.push_back(s);
    for (int i = 0; i < 3; i++) {
        queue<int> q;
        q.push(g[i]);
        dis[i][g[i]] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& v: mp[u]) {
                if (dis[i][v] > dis[i][u] + 1) {
                    dis[i][v] = dis[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++)
        cout << dis[0][i] << (i < n ? " " : "\n");
    for (int i = 1; i <= n; i++)
        cout << dis[1][i] << (i < n ? " " : "\n");
    for (int i = 1; i <= n; i++)
        cout << dis[2][i] << (i < n ? " " : "\n");
    */
    
    dfs(s, t);
    cout << max(ans, max(abs(dis[0][s] - dis[1][s]), abs(dis[0][t] - dis[1][t])));
    return 0;
}