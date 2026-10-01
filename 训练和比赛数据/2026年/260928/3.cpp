#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int solve() {
    int n; cin >> n;
    vector<vector<int>> mp(n + 1);
    vector<pair<int, int>> e;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
        e.emplace_back(u, v);
    }

    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i++)
        deg[i] = mp[i].size();

    int ans = 0;
    for (auto& [u, v]: e)
        ans = max(ans, deg[u] + deg[v] - 2);

    for (int i = 1; i <= n; i++)
        sort(range(mp[i]));

    vector<int> node(n);
    for (int i = 1; i <= n; i++)
        node[i - 1] = i;
    sort(range(node), [&](int& u, int& v){
        return deg[u] > deg[v];
    });

    for (int i = 0; i < n; i++) {
        int& u = node[i];
        for (int j = i + 1; j < n; j++) {
            int& v = node[j];

            if (!binary_search(range(mp[u]), v)) {
                ans = max(ans, deg[u] + deg[v] - 1);
                break;
            }
        }
    }
    return ans;
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