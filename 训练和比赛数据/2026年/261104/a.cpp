#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int l, r; cin >> l >> r;
    int n = r - l + (l < r);
    // if ((l < 0 && 0 < r)) n++;
    // cout << n << "\n";
    int a = abs(l), b = abs(r);
    if (a == b) return 0;
    if (r <= 0 || l >= 0) return n - 1 - (r == 0 || l == 0);
    return n - (2 * min(a, b) + 2);
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