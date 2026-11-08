#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    ll mx = *max_element(range(a));
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] == a[i + 1]) continue;
        const ll& x = max(a[i], a[i + 1]);
        ll y = min(a[i], a[i + 1]);
        int h1 = 64 - __builtin_clzll(x), h2 = 0;
        if (y) h2 = 64 - __builtin_clzll(y);
        for (int j = 0; j <= max(h1, h2); j++) {
            ll t = 1LL << j;
            if (t > x - y) break;
            if ((x & t) == 0 && (y & t) == 0) y += t;
        }
        mx = max(mx, x | y);
    }
    return mx;
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