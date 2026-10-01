#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    ll s = 1LL * n * (n + 1) / 2, r = sqrt(s);
    ll s_sum = r * r;
    if (s_sum == s) {
        cout << -1;
        return;
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }

    s = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        s += ans[i];
        r = sqrt(s);

        if (r * r == s) {
            s += ans[i + 1] - ans[i];
            swap(ans[i], ans[i + 1]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << (i < n ? " " : "");
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