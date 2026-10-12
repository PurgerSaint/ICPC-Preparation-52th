#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    ll x, y; cin >> x >> y;
    ll t = x * y, g = 1;
    ll X = x, Y = y;
    for (ll p = 2; p * p <= max(X, Y); p++) {
        if (x < p && y < p) break;
        int cnt = 0;

        while (x % p == 0) {
            x /= p;
            cnt++;
        }

        while (y % p == 0) {
            y /= p;
            cnt++;
        }

        for (int i = 0; i < cnt / 2; i++)
            g *= p;
    }
    if (x > 1 && x == y) g *= x;
    cout << g << " " << (t / g);
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}