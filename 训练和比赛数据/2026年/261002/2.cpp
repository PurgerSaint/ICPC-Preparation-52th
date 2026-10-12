#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<ll> x, y, z;
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        ll t; cin >> t;
        if (i < l) x.push_back(t);
        else if (i > r) z.push_back(t);
        else {
            sum += t;
            y.push_back(t);
        }
    }
    sort(range(x));
    sort(range(y), greater<ll>());
    sort(range(z));
    ans = sum;
    int m = r - l + 1, m1 = x.size(), m2 = z.size();
    if (!x.empty()) {
        ll s = sum;
        for (int i = 0; i < min(m1, m); i++) {
            s += x[i] - y[i];
            ans = min(ans, s);
        }
    }
    if (!z.empty()) {
        ll s = sum;
        for (int i = 0; i < min(m2, m); i++) {
            s += z[i] - y[i];
            ans = min(ans, s);
        }
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