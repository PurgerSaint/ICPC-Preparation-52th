#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<__int128> s(n + 1, 0);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i - 1];
    int q; cin >> q;
    vector<ll> b(q);
    for (ll& t: b) cin >> t;
    vector<int> c(n + 1, 0);
    for (auto it = b.begin(); it != b.end(); it++) {
        ll& v = *it;
        bool f = 1;
        for (int i = n; i >= 1; i--) {
            if (abs(v) > s[i]) {
                f = 0; break;
            } else if (abs(v) <= s[i - 1]) {
                c[i] = 0;
            } else if (v > s[i - 1]) {
                c[i] = 1, v -= a[i - 1];
            } else if (v < -s[i - 1]) {
                c[i] = -1, v += a[i - 1];
            }
        }
        if (v != 0) f = 0;
        cout << (f ? "YES\n" : "NO");
        if (f) {
            for (int i = 1; i <= n; i++)
                cout << c[i] << (i < n ? " " : "");
        }
        if (it + 1 != b.end()) cout << "\n";
    }
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}