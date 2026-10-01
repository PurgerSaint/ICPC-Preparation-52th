#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

ll solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    if (n == 1) return a[0];
    auto get = [&](int x, int y) -> ll {
        if (x == y) return a[0];
        if (x > y) return a[x - y];
        return a[n - (y - x)];
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << get(i, j) << " ";
        cout << "\n";
    }
    int ax = 0, ay = 0;
    ll ans = get(0, 0);
    const ll INF = 1LL << 60;
    while (true) {
        ll n1 = INF, n2 = INF;
        if (ax + 1 < n) n1 = get(ax + 1, ay);
        if (ay + 1 < n) n2 = get(ax, ay + 1);
        if (n1 < n2 && n1 != INF) ax++, ans += n1;
        else if (n2 < n1 && n2 != INF) ay++, ans += n2;
        else ax++;
        if (ax == n - 1 && ay == n - 1) break;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
}