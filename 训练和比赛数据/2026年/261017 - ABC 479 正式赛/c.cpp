#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; ll k, t; cin >> n >> k >> t;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(range(a));
    ll ans = a[1] > 0, l = 0;
    for (int i = a[1] == 0; i <= n; i++) {
        if (l >= t) break;
        ll r = i + 1 <= n ? a[i + 1] : t;
        if (r > t) r = t;
        if (l < a[i] + k) l = a[i] + k;
        ll dis = r - l, p = dis / k + (dis % k > 0);
        if (p <= 0) continue;
        // cout << a[i] << " " << r << " " << dis << " " << p << "\n";
        ans += p;
        l += p * k;
        if (r == t) break;
    }
    cout << ans;
    return 0;
}