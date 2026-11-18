#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<int> l(n), r(n);
    vector<pair<int, ll>> b;
    for (int i = 0; i < n; i++) {
        b.push_back({i, a[i]});
        if (i > 0) l[i] = i - 1;
        if (i < n - 1) r[i] = i + 1;
    }
    sort(range(b), [&](pair<int, ll>& x, pair<int, ll>& y){ return x.second < y.second; });
    l[0] = n - 1;
    r[n - 1] = 0;
    ll ans = 0;
    for (int i = 0; i < n - 2; i++) ans += b[i].second;
    cout << ans << "\n";
    for (int i = 0; i < n - 2; i++) {
        auto& [j, _] = b[i];
        cout << (l[j] + 1) << " " << (j + 1) << " " << (r[j] + 1) << (i < n - 3 ? "\n" : "");
        r[l[j]] = r[j];
        l[r[j]] = l[j];
    }
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