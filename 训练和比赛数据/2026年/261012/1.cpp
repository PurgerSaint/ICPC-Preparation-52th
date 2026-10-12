#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; ll k; cin >> n >> k;
    int h = 64 - __builtin_clzll(k);
    int num = __builtin_popcountll(k);
    if (n == 1 || h == num || h == num + 1) {
        cout << k;
        for (int i = 2; i <= n; i++)
            cout << " " << 0;
        return;
    }
    ll t = (1LL << (h - 1)) - 1;
    cout << t << " " << (k - t);
    for (int i = 3; i <= n; i++)
        cout << " " << 0;
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