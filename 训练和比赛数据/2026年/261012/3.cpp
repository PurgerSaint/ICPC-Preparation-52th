#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n; cin >> n;
    vector<vector<int>> mp(n + 1);
    vector<int> cnt(n + 1, 0);

    bool f = 0;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;

        cnt[u]++, cnt[v]++;
        mp[u].push_back(v);
        mp[v].push_back(u);

        if (u == v) f = 1;
    }
    if (f) return 0;

    for (int i = 1; i <= n; i++)
        if (cnt[i] != 2)
            return 0;

    vector<bool> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        int c_len = 0, u = i;
        while (!vis[u]) {
            vis[u] = 1;
            c_len++;

            for (int& v: mp[u]) {
                if (!vis[v]) {
                    u = v;
                    break;
                }
            }
        }
        if (c_len % 2) return 0;
    }
    return 1;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        if (t) cout << "\n";
    }
    return 0;
}