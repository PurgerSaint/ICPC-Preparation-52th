#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll get(ll n) {
    ll ans = n / 2 + n / 3 - n / 6;
    ans += n / 5 - n / 10 - n / 15 + n / 30;
    ans += n / 7 - n / 14 - n / 21 - n / 35;
    ans += n / 42 + n / 70 + n / 105 - n / 210;
    return n - ans;
}

ll solve() {
    ll l, r; cin >> l >> r;
    ll cnt_l = get(l - 1), cnt_r = get(r);
    // cout << cnt_l << " " << cnt_r << "\n";
    return cnt_r - cnt_l;
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