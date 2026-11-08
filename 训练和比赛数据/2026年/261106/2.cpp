#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<bool> r(n + 1, 0), c(n + 1, 0);
    vector<vector<ll>> a(n + 1, vector<ll>(n + 1));
    const ll INF = 1LL << 60;
    vector<ll> rn(n + 1, INF), cn(n + 1, INF);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] <= 0) {
                ans += a[i][j];
                r[i] = c[j] = 1;
            } else {
                rn[i] = min(rn[i], a[i][j]);
                cn[j] = min(cn[j], a[i][j]);
            }
        }
    }
    ll ans1 = ans;
    for (int i = 1; i <= n; i++) {
        if (r[i]) continue;
        if (rn[i] != INF) ans1 += rn[i];
    }
    ll ans2 = ans;
    for (int j = 1; j <= n; j++) {
        if (c[j]) continue;
        if (cn[j] != INF) ans2 += cn[j];
    }
    return min(ans1, ans2);
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