#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i - 1];
    vector<ll> pre_max(n + 1, 0), pre_min(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre_max[i] = max(pre_max[i - 1], s[i]);
        pre_min[i] = min(pre_min[i - 1], s[i]);
    } 
    vector<ll> suf_max(n + 1, 0), suf_min(n + 1, 0);
    suf_max[n] = suf_min[n] = s[n];
    for (int i = n - 1; i >= 1; i--) {
        suf_max[i] = max(suf_max[i + 1], s[i]);
        suf_min[i] = min(suf_min[i + 1], s[i]);
    } 
    ll ans = pre_max[n] - pre_min[n] + 1;
    for (int i = 1; i <= n; i++) {
        ll l = min(pre_min[i - 1], suf_min[i] - 2 * a[i - 1]);
        ll r = max(pre_max[i - 1], suf_max[i] - 2 * a[i - 1]);
        ans = max(ans, r - l + 1);
    }
    // cout << l << " " << r << "\n";
    cout << ans;
    return 0;
}