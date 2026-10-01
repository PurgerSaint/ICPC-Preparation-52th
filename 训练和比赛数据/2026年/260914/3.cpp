#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

void solve() {
    ll x; cin >> x;
    ll l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1; 
    }
    r = ans;
    cout << r << " " << (x - r * r) << " " << ((r + 1) * (r + 1) - x);
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