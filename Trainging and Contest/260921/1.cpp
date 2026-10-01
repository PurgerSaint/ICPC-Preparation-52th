#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        if (b > d) ans += a + (b - d);
        else if (a > c) ans += (a - c);
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