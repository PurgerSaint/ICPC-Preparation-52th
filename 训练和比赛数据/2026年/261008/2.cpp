#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> mp(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    vector<int> cnt(n + 1, 0);
    auto dfs = [&](auto& self, int u, int p) -> void {
        cnt[u] = 1;
        for (int& v: mp[u]) {
            if (v != p) {
                self(self, v, u);
                cnt[u] += cnt[v];
            }
        }
    };
    dfs(dfs, 1, 0);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll r = sqrt(a[i]);
        if (r * r != a[i]) continue;

        vector<ll> branch;
        for (int& v: mp[i]) {
            if (cnt[v] < cnt[i]) {
                branch.push_back(cnt[v]);
            } else {
                branch.push_back(n - cnt[i]);
            }
        }

        ll s1 = n - 1, s2 = 0, s3 = 0;
        for (ll& s: branch) {
            s2 += s * s;
            s3 += s * s * s;
        }

        ll e2 = (s1 * s1 - s2) / 2;
        ll e3 = (s1 * s1 * s1 - 3 * s1 * s2 + 2 * s3) / 6;

        ans += e2 + e3;
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