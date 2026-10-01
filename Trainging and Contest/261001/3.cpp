#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
}

int main() {
    ios;
    int n = 2;
    ll s = 1;
    ll mx = 25 * pow(10, 10);
    mx = mx * (mx + 1) / 2;
    while (s <= mx) {
        s += n * n;
        ll r = sqrt(s);
        if (r * r == s) {
            cout << n << " " << s << "\n";
            // break;
        }
        n++;
    }
    cout << "end:" << n << " " << s << "\n";
    return 0;
}