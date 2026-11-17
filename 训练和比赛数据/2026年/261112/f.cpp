#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> ans(n + 1, 0);
    for (int x = 1; x <= n; x++) {
        int i = (n - x + 1) + b[x];
        if (i < 1 || i > n) {
            cout << -1; return;
        }
        ans[i] = x;
    }
    for (int i = 1; i <= n; i++)
        if (ans[i] == 0) {
            cout << -1; return;
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