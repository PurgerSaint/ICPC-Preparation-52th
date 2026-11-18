#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    ll X, B, D; cin >> X >> B >> D;
    if (X <= B) return 0;
    ll d = min(B, D), pw = 1;
    while (pw * 2 * B < X) pw *= 2;
    ll rem = X - pw * B;
    ll r = min(pw, (rem + d - 1) / d);
    return pw + r - 1;
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