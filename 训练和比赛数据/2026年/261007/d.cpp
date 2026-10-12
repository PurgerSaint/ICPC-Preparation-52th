#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct Lab {
    ll a, b, c, s, f;
};

ll solve() {
    int n; cin >> n;
    ll k; cin >> k;
    
    vector<Lab> arr(n);
    ll min_s = 1LL << 60;

    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;

        ll s = a + b + c;
        min_s = min(min_s, s);

        ll f = 0;
        if (a == b && b == c) {
            f = -1;
        } else if (a <= b && b <= c) {
            f = 1LL << 60;
            if (a < c) f = min(f, b - a + 1);
            if (a < b) f = min(f, c - b + 1);
        }

        arr[i] = {a, b, c, s, f};
    }

    auto check = [&](ll mid) -> bool {
        ll cost = 0;
        for (const auto& lab: arr) {
            if (lab.s >= mid) continue;
            if (lab.f == -1) return 0;

            cost += (mid - lab.s) + 2 * lab.f;

            if (cost > k) return 0;
        }
        return cost <= k;
    };

    ll l = min_s, r = min_s + k;
    ll ans = min_s;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
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