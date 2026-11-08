#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    ll n, k; cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(3));
    for (vector<ll>& p: a) cin >> p[0] >> p[1] >> p[2];
    sort(range(a), [](vector<ll>& x, vector<ll>& y){
        return x[0] + x[1] + x[2] < y[0] + y[1] + y[2];
    });
    ll l = a[0][0] + a[0][1] + a[0][2], r = a[n - 1][0] + a[n - 1][1] + a[n - 1][2] + k;
    auto check = [&](ll mid) -> bool {
        ll cnt = 0;
        for (vector<ll>& p: a) {
            ll s = p[0] + p[1] + p[2];
            if (s >= mid) break;
            if (p[0] > p[1] || p[0] > p[2] || p[1] > p[2]) cnt += mid - s;
            else if (p[0] == p[1] && p[1] == p[2]) return 0;
            else cnt += (mid - s) + 2 * min(p[1] - p[0] + 1, p[2] - p[1] + 1);
            if (cnt > k) return 0;
        }
        return cnt <= k;
    };
    ll ans = l;
    while (l <= r) {
        ll mid = l + ((r - l) / 2);
        if (check(mid)) {
            ans = max(mid, ans);
            l = mid + 1;
        } else r = mid - 1;
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