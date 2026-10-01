#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

ll solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    if (n == 1) return a[0];
    ll sum = a[0];
    ll ans = 1LL << 60, cnt = n;
    for (int i = n - 1; i - 1 > 0; i--) {
        cnt--;
        ll res = sum * 2 + (cnt * a[i]) + (cnt - 1) * a[i - 1];
        // cout << cnt << " " << a[i] << " " << a[i - 1] << " " << res << "\n";
        ans = min(ans, res);
        sum += a[i];
    }
    sum = a[0], cnt = n;
    for (int i = 1; i + 1 < n; i++) {
        cnt--;
        ll res = sum * 2 + cnt * a[i] + (cnt - 1) * a[i + 1];
        // cout << cnt << " " << a[i] << " " << a[i - 1] << " " << res << "\n";
        ans = min(ans, res);
        sum += a[i];
    }
    ans = min(ans, a[0] * n + (n - 1) * min(a[1], a[n - 1]));
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
}