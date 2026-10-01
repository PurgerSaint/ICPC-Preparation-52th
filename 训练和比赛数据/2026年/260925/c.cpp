#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

ll solve() {
    int n; ll x; cin >> n >> x;
    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (x == 1) return 0;
    
    vector<ll> fact;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            fact.push_back(i);
            if (i * i != x) fact.push_back(x / i);
        }
    }
    
    ll ans = 0;
    for (ll& d: fact) {
        if (d == 1) continue;
        ll res = 0;
        for (ll& t: a)
            if (t % d == 0)
                res += t;
        ans = max(ans, res);
    }
    return ans;
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