#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

ll solve() {
    ll n, m; cin >> n >> m;
    ll t = (n + 1) / 2, l = m - t;
    if (t == m) return 1;
    return (m - t) * 2 + 1;
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