#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct state {
    int v; ll w;
    int cnt;
    bool operator<(const state& other) const {
        if (cnt != other.cnt) return cnt > other.cnt;
        return w > other.w;
    }
};

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
    vector<ll> cnt(n + 1, INF);
    priority_queue<state> q;
    q.push({1, 0, 0});
    dis[1] = 0;
    cnt[1] = 0;
    while (!q.empty()) {
        state t = q.top(); q.pop();
        auto& [u, w, ct] = t;
        if (w != dis[u] || ct != cnt[u]) continue;
        for (auto& [v, c]: mp[u]) {
            ll w2 = w * 10 + c;
            int n_ct = ct;
            if (w2 >= MOD) n_ct += w2 / MOD;
            w2 = mod(w2, MOD);

            if (n_ct < cnt[v] || (n_ct == cnt[v] && w2 < dis[v])) {
                dis[v] = w2;
                cnt[v] = n_ct;
                q.push({v, dis[v], n_ct});
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << dis[i] << (i < n ? "\n" : "");
    return 0;
}