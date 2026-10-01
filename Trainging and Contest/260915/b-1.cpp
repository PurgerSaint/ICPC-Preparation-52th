#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int u;
    ll d, r;
    bool operator<(const state& other) const {
        if (d != other.d) return d > other.d;
        return r > other.r;
    }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<state>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll d, r; cin >> u >> v >> d >> r;
        mp[u].push_back({v, d, r});
    }
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF), rk(n + 1, INF);
    priority_queue<state> pq;
    dis[1] = 0;
    rk[1] = 0;
    pq.push({1, dis[1], rk[1]});
    while (!pq.empty()) {
        auto [u, d, r] = pq.top(); pq.pop();
        if (d != dis[u] || r != rk[u]) continue;
        if (u == n) break;
        for (auto& [v, d1, r1]: mp[u]) {
            if (d + d1 < dis[v]) {
                dis[v] = d + d1;
                rk[v] = r + r1;
                pq.push({v, dis[v], rk[v]});
            }
            if (d + d1 == dis[v] && r + r1 < rk[v]) {
                rk[v] = r + r1;
                pq.push({v, dis[v], rk[v]});
            }
        }
    }
    if (dis[n] == INF) cout << "-1 -1";
    else cout << dis[n] << " " << rk[n];
    return 0;
}