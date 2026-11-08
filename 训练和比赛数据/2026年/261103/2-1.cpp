#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    string f; cin >> f;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<ll> s(n, 0);
    s[0] = a[0];
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i];
    auto get = [&](int l, int r) -> ll {
        return s[r] - (l > 0 ? s[l - 1] : 0);
    };
    ll ans = 0, mn = 1LL << 60;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] == '1') {
            cnt++;
            mn = min(mn, a[i]);
            if (i > 0 && cnt == 1) mn = min(mn, a[i - 1]);
        } else {
            if (cnt > 0) ans += get(i - cnt - 1, i - 1) - (i == cnt ? 0 : mn);
            cnt = 0;
            mn = 1LL << 60;
        }
    }
    if (cnt > 0) ans += get(n - cnt - 1, n - 1) - (n == cnt ? 0 : mn);
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