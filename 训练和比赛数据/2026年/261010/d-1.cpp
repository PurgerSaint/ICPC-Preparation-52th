#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; ll m, k; cin >> n >> m >> k;
    vector<pair<ll, ll>> a(n);
    for (auto& [l, r]: a) cin >> l >> r;
    sort(range(a));
    if (a[n - 1].second - a[n - 1].first + 1 >= k) return a[n - 1].second - k + 1;

    vector<ll> s(n, 0);
    s[0] = a[0].second - a[0].first + 1;
    for (int i = 1; i < n; i++) {
        auto& [l, r] = a[i];
        s[i] = s[i - 1] + (r - l + 1);
    }

    ll pre = 0;
    for (int i = 0; i < n; i++) {
        auto& [l, r] = a[i];
        ll l_uf = l - 1;
        if (i > 0) l_uf = l - a[i - 1].second;

        auto it = lower_bound(range(s), pre + k);
        if (it != s.end()) {
            auto& [l1, r1] = a[it - s.begin()];

            ll sz = r1 - l + 1, r_uf = 1LL << 60;
            ll t = *it - pre;
            if (it + 1 != s.end()) r_uf = a[it - s.begin() + 1].first - r1;

            if (t == k) {
                if (sz + r_uf >= m) return l;
                if (l_uf + sz + r_uf >= m) return r1 + r_uf - m + 1;
            }
            if (sz - t == m - k && t > k) return l;
            if (t > k && sz + l_uf >= m) return l1 + (k - (t - (r - l + 1))) - m + 1;
        }
        pre += r - l + 1;
    }
    return -1;
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