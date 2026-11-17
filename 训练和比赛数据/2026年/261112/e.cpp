#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

string solve() {
    int n, k; cin >> n >> k;
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        if (i % (k + 1) == 1) s += a;
    }
    return s % 2 == 1 ? "Alice" : "Bob";
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