#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<ll> x(n);
    for (ll& t: x) cin >> t;
    for (int i = 0; i < n; i++) {
        ll ans = 0;
        if (i == 0 || i == n - 1) ans = (x[n - 1] - x[0]) / 2;
        else {
            ll ans1 = (x[i + 1] - x[i]) / 2 + max((x[i] - x[0]) / 2, (x[n - 1] - x[i + 1]) / 2);
            ll ans2 = (x[i] - x[i - 1]) / 2 + max((x[n - 1] - x[i]) / 2, (x[i - 1] - x[0]) / 2);
            ans = min(ans1, ans2);
        }
        cout << ans;
        if (i < n - 1) cout << "\n";
    }
    return 0;
}