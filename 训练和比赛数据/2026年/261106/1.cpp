#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> a, b;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        if (t % 2 == 1) a.push_back(t);
        else b.push_back(t);
    } 
    int c1 = a.size(), c2 = n - c1;
    if (c1 == n || c2 == n) return 0;
    sort(range(a));
    sort(range(b));
    ll t = a.back();
    for (int i = 0; i < c2; i++) {
        if (b[i] > t) break;
        if (t > b.back()) return c2;
        t += b[i];
    }
    return c2 + 1;
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