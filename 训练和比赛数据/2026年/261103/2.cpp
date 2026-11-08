#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    ll ans = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            mn = a[i];
        } else {
            ans += max(mn, a[i]);
            mn = min(mn, a[i]);
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