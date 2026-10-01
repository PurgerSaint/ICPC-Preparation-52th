#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int u; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    const ll INF = 1LL << 60;
    int n, m, k; cin >> n >> m >> k;
    vector<ll> d(k + 1, 0), dis(n + 1, INF);
    vector<vector<int>> mp(n + 1);
    vector<int> good(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> good[i];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    priority_queue<state> pq;
    dis[1] = 0;
    d[good[1]] = dis[1];
    pq.push({1, 0});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (dis[u] != w) continue;
        for (int& v: mp[u]) {
            if (w + 1 < dis[v]) {
                dis[v] = w + 1;
                d[good[v]] = max(d[good[v]], dis[v]);
                pq.push({v, w + 1});
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << d[i] << (i < k ? " " : "");
    }
    return 0;
}