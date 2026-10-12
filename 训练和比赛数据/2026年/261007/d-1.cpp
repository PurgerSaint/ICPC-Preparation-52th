#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    ll k; cin >> k;
    ll ans = 1LL << 60;
    for (int i = 1; i <= n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        ll s = a + b + c, t = s;
        if (a == b && b == c && c == a) {
            ans = min(ans, s);
            continue;
        }
        if (a > b || a > c || b > c) {
            //cout << i << " " << (s + k) << "\n";
            ans = min(ans, s + k);
            continue;
        }
        if (a < b && c >= min(a, b)) {
            t = max(t, s + max(k - (c - min(a, b) + 1), 0LL));
        }
        if (a < c && b >= min(a, c)) {
            t = max(t, s + max(k - (b - min(a, c) + 1), 0LL));
        }
        if (b < c && a >= min(c, b)) {
            t = max(t, s + max(k - (a - min(c, b) + 1), 0LL));
        }
        //cout << i << " " << t << "\n";
        ans = min(ans, t);
    }
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