#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector<vector<pair<int, int>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back({v, 1});
    }    
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>>& p = mp[i];
        if (p.empty()) continue;
        sort(range(p), [](pair<int, int>& a, pair<int, int>& b){
            return a.first < b.first;
        });
        p[0].second = 0;
    }
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    deque<int> q;
    q.push_front(s);
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        if (u == t) break;
        for (auto& [v, w]: mp[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (w) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    if (dis[t] == INF) cout << -1;
    else cout << dis[t];
    return 0;
}