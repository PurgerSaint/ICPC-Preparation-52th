#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int n;
vector<vector<int>> mp;
vector<int> cnt;

int dfs(int u, int pa) {
    for (int& v: mp[u]) {
        if (v == pa) continue;
        cnt[u] += dfs(v, u);
    }
    return cnt[u];
}

int solve() {
    cin >> n;
    mp = vector<vector<int>>(n + 1);
    cnt = vector<int>(n + 1, 1);
    for (int i = 0; i + 1 < n; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    if (n % 2 == 0) return n + 1;
    // dfs(1, 0);
    vector<pair<int, int>> ans = {{n, n}, {n + 1, (n + 1) / 2}, {n + 2, 1}};
    for (auto& [k, x]: ans) {
        if ((int)mp[x].size() <= 1) continue;
        return k;
    }
    return ans[0].first;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}