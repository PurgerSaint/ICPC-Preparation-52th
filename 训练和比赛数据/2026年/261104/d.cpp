#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int solve() {
    int n; cin >> n;
    vector<vector<int>> mp(n + 1);
    for (int i = 0; i + 1 < n; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    if (n % 2 == 0) return n + 1;
    vector<pair<int, int>> ans = {{n, n}, {n + 1, (n + 1) / 2}, {n + 2, 1}};
    auto check = [&](int k, int x) -> bool {
        if (mp[x].size() <= 1) return 0;

        vector<int> color(n + 1, 0);
        for (int& i: mp[x]) {
            stack<pair<int, int>> st;
            st.push({i, x});
            color[i] = i;
            
            while (!st.empty()) {
                auto [u, pa] = st.top(); st.pop();
                for (int& v: mp[u]) {
                    if (v == pa || color[v] > 0) continue;
                    color[v] = i;
                    st.push({v, u});
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            int j = k - i;
            if (1 <= j && j <= n && i != j && i != x && j != x && color[i] != color[j]) 
                return 1;
        }
        return 0;
    };
    for (auto& [k, x]: ans)
        if (check(k, x)) return k;
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