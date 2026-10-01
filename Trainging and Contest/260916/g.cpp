#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, q; cin >> n >> q;
    map<ll, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        ll t; cin >> t;
        mp[t].push_back(i);
    }
    while (q--) {
        ll x, y; cin >> x >> y;
        if (!mp.count(x) || !mp.count(y)) {
            cout << 0 << (q ? "\n" : "");
            continue;
        }
        vector<int>& loc_x = mp[x];
        vector<int>& loc_y = mp[y];
        if (loc_x[0] >= loc_y.back()) {
            cout << 0 << (q ? "\n" : "");
            continue;
        }
        int ans = 0;
        auto it = lower_bound(range(loc_x), loc_y[0]);
        ans += (it - loc_x.begin()) * loc_y.size();
        // cout << ans << "\n";
        for (auto i = it; i != loc_x.end(); i++) {
            auto it1 = upper_bound(range(loc_y), *i);
            if (it1 == loc_y.end()) break;
            ans += loc_y.end() - it1;
        }
        cout << ans << (q ? "\n" : "");
    }
    return 0;
}