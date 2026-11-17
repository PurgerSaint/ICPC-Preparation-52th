#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    ll l, r; cin >> l >> r;
    ll c = max(63 - __builtin_clzll(l), 63 - __builtin_clzll(r));
    ll t = 1LL << c;
    while (t <= l) {
        l -= t, r -= t;
        c = max(63 - __builtin_clzll(l), 63 - __builtin_clzll(r)), t = 1LL << c;
        // cout << l << " " << r << " " << c << " " << t << "\n";
        if (l < t && t <= r) break;
    }
    return l;
}

int main() {
    ios;
    ll t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}