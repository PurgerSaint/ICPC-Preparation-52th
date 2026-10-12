#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int solve() {
    int n; cin >> n;
    vector<ll> a(n), x, y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2) x.push_back(a[i]);
        else y.push_back(a[i]);
    }
    sort(range(a));
    sort(range(x));
    sort(range(y));
    int m1 = x.size(), m2 = y.size();
    if (m1 == n || m2 == n) return 0;
    
    ll s = x.back();
    for (ll& t: y) {
        if (s > t) s += t;
        else return m2 + 1;
    } 
    
    return m2;
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