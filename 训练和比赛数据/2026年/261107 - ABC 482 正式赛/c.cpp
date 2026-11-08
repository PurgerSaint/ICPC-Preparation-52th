#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> b(n - 1);
    for (int i = 1; i <= n - 1; i++)
        b[i - 1] = {i, i + 1};
    sort(range(b), [&](pair<int, int>& x, pair<int, int>& y){
        return abs(a[x.second] - a[x.first]) < abs(a[y.second] - a[y.first]);
    });
    vector<ll> diff(n - 1, 0);
    for (int i = 0; i < n - 1; i++)
        diff[i] = abs(a[b[i].first] - a[b[i].second]);
    auto check = [&](ll mid) -> bool {
        int cnt = diff.end() - upper_bound(range(diff), mid);
        if (cnt > 2) return 0;
        if (cnt == 2) {
            vector<int> c;
            for (int i = n - 2; i >= n - 3; i--) {
                c.push_back(b[i].first);
                c.push_back(b[i].second);
            }
            sort(range(c));
            if (abs(a[c[0]] - 2 * a[c[2]]) > mid || abs(a[c[3]] - 2 * a[c[1]]) > mid) return 0;
            ll t = 0;
            for (int i = c[1] + 1; i <= c[2]; i++)  {
                t = max(t, abs(a[i] - a[i - 1]));
                if (2 * t > mid) return 0;
            }
            return 1;
        }
        ll l = b.back().first, r = b.back().second;
        ll t = 0;
        for (int i = r; i <= n; i++) {
            if (i > r) t = max(t, abs(a[i] - a[i - 1]));
            bool f = abs(a[l] - 2 * a[i]) <= mid && 2 * t <= mid;
            if (i + 1 <= n) f = f && abs(a[i + 1] - 2 * a[r]) <= mid;
            if (f) {
                // cout << "L " << mid << " " << l << " " << r << " " << i << "\n";
                return 1;
            }
            if (t * 2 > mid) break;
        }
        t = 0;
        for (int i = l; i >= 1; i--) {
            if (i < l) t = max(t, abs(a[i + 1] - a[i]));
            bool f = abs(a[r] - 2 * a[i]) <= mid && 2 * t <= mid;
            if (i - 1 >= 1) f = f && abs(a[i - 1] - 2 * a[l]) <= mid;
            if (f) {
                // cout << "R " << mid << " " << l << " " << r << " " << i << "\n";
                return 1;
            }
            if (t * 2 > mid) break;
        }
        return 0;
    };
    ll l = 0, r = diff.back();
    ll ans = diff.back();
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
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