#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int ch[2] = {0};
};
vector<state> node(1);

void insert(const ll& x) {
    int u = 0;
    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (node[u].ch[b] == 0) {
            node[u].ch[b] = node.size();
            node.emplace_back();
        }
        u = node[u].ch[b];
    }
}

ll find(const ll& x) {
    int u = 0;
    ll res = 0;
    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1, wt = b ^ 1;
        if (node[u].ch[wt] != 0) {
            res |= 1 << i;
            u = node[u].ch[wt];
        } else u = node[u].ch[b];
    }
    return res;
}

int main() {
    ios;
    int n; cin >> n;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].emplace_back(v, w);
        mp[v].emplace_back(u, w);
    }
    vector<ll> dis(n + 1, 0);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        insert(dis[u]);
        for (auto& [v, w]: mp[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            dis[v] = dis[u] ^ w;
            q.push(v);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, find(dis[i]));
    cout << ans;
    return 0;
}