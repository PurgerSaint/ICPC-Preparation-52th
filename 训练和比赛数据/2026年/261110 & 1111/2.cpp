#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, q; ll k; cin >> n >> k >> q;  
    ll s = 0;
    vector<pair<int, int>> mission(n);
    for (auto& [a, b]: mission) {
        cin >> a >> b;
        s += b;
    }
    vector<vector<ll>> ans(2, vector<ll>(n, 0));
    ll t = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            auto& [a, b] = mission[j];
            ans[i][j] = max(t, i * k + (a - 1)) + b;
            t = ans[i][j];
        }
    }
    while (q--) {
        int x, y; cin >> x >> y;
        ll t;
        if (x == 1) t = ans[0][y - 1];
        else t = (ans[1][y - 1] + (x - 2) * max(s, k));
        // cout << t << "\n";
        ll d = t / k + (t % k > 0), h = t % k;
        if (h == 0) h = k;
        cout << d << " " << h;
        if (q) cout << "\n";
    }
    return 0;
}