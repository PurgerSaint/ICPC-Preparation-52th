#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

struct state {
    int ch[2] = {0};
};
vector<state> trie;

void insert(const int& x) {
    int u = 0;

    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (trie[u].ch[b] == 0) {
            trie[u].ch[b] = trie.size();
            trie.emplace_back();
        }
        u = trie[u].ch[b];
    }
}

int query(const int& x) {
    int u = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1;
        int t = b ^ 1;
        if (trie[u].ch[t]) {
            res |= (1 << i);
            u = trie[u].ch[t];
        } else u = trie[u].ch[b];
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
    vector<int> parent(n + 1, 0);
    vector<ll> dis(n + 1, 0);
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    dis[1] = 0;
    trie.emplace_back();
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& [v, w]: mp[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            dis[v] = dis[u] ^ w;
            q.push(v);

            int x = 0;
            for (int i = 30; i >= 0; i--) {
                int b = (dis[v] >> i) & 1;
                if (trie[x].ch[b] == 0) {
                    trie[x].ch[b] = trie.size();
                    trie.emplace_back();
                }
                x = trie[x].ch[b];
            }
        }
    }
    ll ans = 0;
    for (int k = 1; k <= n; k++) {
        int u = 0;
        ll res = 0;
        
        for (int i = 30; i >= 0; i--) {
            int b = (dis[k] >> i) & 1;
            int t = b ^ 1;
            if (trie[u].ch[t]) {
                res |= (1 << i);
                u = trie[u].ch[t];
            } else u = trie[u].ch[b];
        }
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}
