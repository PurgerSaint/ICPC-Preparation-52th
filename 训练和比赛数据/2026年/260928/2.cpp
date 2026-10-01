#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

ll solve() {
    int n, k; cin >> n >> k;
    vector<ll> l(n), r(n);
    for (ll& t: l) cin >> t;
    for (ll& t: r) cin >> t;

    ll ans = 0;
    vector<ll> mn(n);
    for (int i = 0; i < n; i++) {
        ans += max(l[i], r[i]);
        mn[i] = min(l[i], r[i]);
    }
    sort(range(mn), greater<ll>());
    return ans + accumulate(mn.begin(), mn.begin() + k - 1, 0LL) + 1;
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