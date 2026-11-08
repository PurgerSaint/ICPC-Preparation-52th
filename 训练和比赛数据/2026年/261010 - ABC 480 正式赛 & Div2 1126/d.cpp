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

    ll s_uf = a[0].first > 1 ? (a[0].first - 1) : 0LL, uf = m - k;
    for (int i = 0; i < n; i++) {
        auto& [l, r] = a[i];

        ll f = r - l + 1;                               // 当前的感染人数
        ll l_uf = s_uf, r_uf = 1LL << 60;               // 左右未感染的人数
        if (i > 0) l_uf = l - a[i - 1].second - 1;
        if (i + 1 < n) r_uf = a[i + 1].first - r - 1;

        if (f >= k) {   // 当前就已经满足符合感染的人数
            // 左侧未感染人数符合
            if (uf <= l_uf) return l - uf;
            // 右侧未感染人数符合
            if (uf <= r_uf) return r - k + 1;
        }

        ll c_f = f, c_uf = r_uf;
        for (int j = i + 1; j < n; j++) {   // 向右枚举
            if (c_uf > uf || c_f > k) break;

            auto& [l1, r1] = a[j];
            if (l1 - l > m) break;

            c_f += r1 - l1 + 1;

            // 未感染人数符合 且 感染人数超过预期
            if (c_uf == uf && c_f >= k) return l;

            ll n_cf = 1LL << 60;
            if (j + 1 < n) n_cf = a[j + 1].first - r1 - 1;

            if (c_f == k) { // 感染人数符合
                // 未感染人数也符合 或 加上当前右侧的未感染人数超预期
                if (c_uf == uf || c_uf + n_cf >= uf) return l;
                // 原左侧感染人数加上中间的未感染人数超过预期
                if (l_uf + c_uf >= uf) return r1 - m + 1;
                // 左中右未感染人数和超预期
                if (l_uf + c_uf + n_cf >= uf) return l - l_uf;
            }
            c_uf += n_cf;
        }

        c_f = f, c_uf = l_uf;
        for (int j = i - 1; j >= 0; j--) {      // 向左枚举
            if (c_uf > uf || c_f > k) break;

            auto& [l1, r1] = a[j];
            c_f += r1 - l1 + 1;

            if (c_uf == uf && c_f >= k) return l1;

            ll n_cf = 1LL << 60;
            if (j - 1 >= 0) n_cf = l1 - a[j - 1].second - 1;

            if (c_f == k) {
                if (c_uf == uf || r_uf + c_uf >= uf) return l1;
                if (c_uf + n_cf >= uf) return r - m + 1;
                if (r_uf + c_uf + n_cf >= uf) return l1 - n_cf;
            }
            c_uf += n_cf;
        }
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