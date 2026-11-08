#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    ll s = 0, mn = 1LL << 60;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll t; cin >> t;
        if (t < 0) cnt++;
        s += abs(t);
        mn = min(mn, abs(t));
    }

    if (cnt % 2 == 0) return s;
    return s - 2LL * mn;
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