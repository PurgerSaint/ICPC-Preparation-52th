#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i - 1];
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + b[i];
    vector<ll> c(n + 1);
    for (int i = 1; i <= n; i++) c[i] = c[i - 1] + i;
    auto sum = [&](ll x) -> ll {
        if (x == 0) return 0;
        int pos = lower_bound(range(c), x) - c.begin();
        x -= c[pos - 1];
        return s[pos - 1] + b[x];
    };
    while (q--) {
        ll l, r; cin >> l >> r;
        cout << (sum(r) - sum(l - 1)) << (q ? "\n" : "");
    }
    return 0;
}