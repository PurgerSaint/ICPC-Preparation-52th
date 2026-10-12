#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    if (n == 1 || m == 1) return 0;
    ll ans = 2 * (n - 1) + 2 * (m - 1);
    if (x > 1 && x < n) ans += 2 * (m - 1);
    if (y > 1 && y < m) ans += 2 * (n - 1);
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