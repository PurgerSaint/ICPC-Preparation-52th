#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    ll n; cin >> n;
    ll x = 0, y = 0, p = 1;
    int t = 0;
    while (n > 0) {
        int d = n % 10;
        n /= 10;
        if (d % 2 == 0) {
            x += d / 2 * p;
            y += d / 2 * p;
        } else {
            x += (d + (t == 1)) / 2 * p;
            y += (d + (t == 0)) / 2 * p;
            t ^= 1;
        }
        p *= 10;
    }
    cout << x << " " << y;
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