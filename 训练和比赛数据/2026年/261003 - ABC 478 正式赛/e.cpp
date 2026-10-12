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
    for (int i = 1; i <= m; i++) {
        int f, u, v; cin >> f >> u >> v;
        mp[u].emplace_back(v, f);
    }

    vector<int> dfn(n + 1, 0), low(n + 1, 0), scc(n + 1, 0);
    vector<bool> in_st(n + 1, 0);
    stack<int> st;
    int timer = 0, scc_cnt = 0;

    function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++timer;
        st.push(u);
        in_st[u] = 1;

        for (auto& [v, t]: mp[u]) {
            if (dfn[v] == 0) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (in_st[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            scc_cnt++;
            while (!st.empty()) {
                int v = st.top(); st.pop();
                in_st[v] = 0;
                scc[v] = scc_cnt;
                if (u == v) break;
            }
        }
    };

    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0) tarjan(i);

    vector<vector<pair<int, int>>> dag(scc_cnt + 1);
    vector<int> in(scc_cnt + 1, 0);

    for (int u = 1; u <= n; u++) {
        for (auto& [v, w]: mp[u]) {
            if (scc[u] == scc[v]) {
                if (w == 1) {
                    cout << "No";
                    return 0;
                }
            } else {
                dag[scc[u]].push_back({scc[v], w});
                in[scc[v]]++;
            }
        }
    }

    queue<int> q;
    vector<int> ans(scc_cnt + 1, 1);

    for (int i = 1; i <= scc_cnt; i++)
        if (in[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& [v, w]: dag[u]) {
            ans[v] = max(ans[v], ans[u] + w);
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[scc[i]] > n) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes" << "\n";
    for (int i = 1; i <= n; i++)
        cout << ans[scc[i]] << (i < n ? " " : "");
    return 0;
}