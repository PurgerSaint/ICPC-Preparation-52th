#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll& t: a) cin >> t;
    for (ll& t: b) cin >> t;
    sort(range(a));
    sort(range(b));
    deque<ll> x, y;
    for (ll& t: a) x.push_back(t);
    for (ll& t: b) y.push_back(t);
    ll ans = 0;
    bool f = 1;
    while (!x.empty()) {
        ll bf = y.front(), bk = y.back();
        ll af = x.front(), ak = x.back();
        ll d1 = abs(ak - bf), d2 = abs(bk - af);
        if (d1 > d2) {
            ans += d1, x.pop_back(), y.pop_front();
        } else {
            ans += d2, x.pop_front(), y.pop_back();
        }
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