#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    ll h, w; int n, q; cin >> h >> w >> n >> q;
    map<ll, ll> cnt_r, cnt_c;
    cnt_r[0] = 0, cnt_c[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll x, y; cin >> x >> y;
        cnt_r[x]++; cnt_c[y]++;
    }
    map<ll, ll> s_r, s_c;
    s_r[0] = 0, s_c[0] = 0;
    for (auto it = cnt_r.begin(); it != cnt_r.end(); it++) {
        auto& [r, cnt] = *it;
        if (r == 0) continue;
        else s_r[r] = (*s_r.rbegin()).second + cnt;
    }
    for (auto it = cnt_c.begin(); it != cnt_c.end(); it++) {
        auto& [c, cnt] = *it;
        if (c == 0) continue;
        else s_c[c] = (*s_c.rbegin()).second + cnt;
    }
    auto get_r = [&](ll x) -> ll {
        auto it = s_r.lower_bound(x);
        if (it == s_r.end()) return (*s_r.rbegin()).second;
        if ((*it).first > x) return (*prev(it)).second;
        return (*it).second;
    };
    auto get_c = [&](ll x) -> ll {
        auto it = s_c.lower_bound(x);
        if (it == s_c.end()) return (*s_c.rbegin()).second;
        if ((*it).first > x) return (*prev(it)).second;
        return (*it).second;
    };
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            ll u, d; cin >> u >> d;
            cout << (get_r(d) - get_r(u - 1)) << (q ? "\n" : "");
        } else {
            ll l, r; cin >> l >> r;
            cout << (get_c(r) - get_c(l - 1)) << (q ? "\n" : "");
        }
    }
    return 0;
}