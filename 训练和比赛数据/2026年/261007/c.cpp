#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> pos;
    vector<vector<int>> x;
    vector<vector<int>> y;
    for (int i = 1; i + 4 <= n; i++) {
        ll r = a[i] + a[i + 2] - a[i + 4];
        // cout << i << " " << r << "\n";
        int t = 0;
        if (!pos.count(r)) {
            pos[r] = x.size();
            if (i % 2) {
                x.push_back({i});
                y.push_back({});
            } else {
                x.push_back({});
                y.push_back({i});
            }
        } else {
            if (i % 2) x[pos[r]].push_back(i);
            else y[pos[r]].push_back(i);
        }
    }
    // cout << "\n";
    ll ans = 0;
    for (auto& [_, i]: pos) {
        vector<int>& h = x[i];
        vector<int>& g = y[i];
        ans += 1LL * h.size() * g.size();
        for (int& j: h)
            ans += h.end() - lower_bound(range(h), j + 5);
        for (int& j: g)
            ans += g.end() - lower_bound(range(g), j + 5);
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