#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, m; ll k; cin >> n >> m >> k;
    ll x, y; cin >> x >> y;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(range(a));
    sort(range(b));
    vector<ll> s(n, 0);
    s[0] = a[0];
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i];
    int ans = upper_bound(range(s), x + y * k) - s.begin();
    for (int i = 0; i < m; i++) {
        ll nd = b[i] / k + (b[i] % k > 0);
        if (nd > y) break;
        y -= nd;
        if (b[i] % k) x += k - (b[i] % k);
        int ca = upper_bound(range(s), x + y * k) - s.begin();
        ans = max(ans, i + 1 + ca);
    }
    cout << ans;
    return 0;
}