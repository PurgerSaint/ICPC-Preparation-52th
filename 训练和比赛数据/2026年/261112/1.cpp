#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<bool> vis(n + 1, 0);
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (!vis[t]) {
            ans[i] = t, vis[t] = 1;
        }
    }
    int num = 1;
    for (int i = 1; i <= n; i++) {
        if (ans[i] != 0) continue;
        while (num <= n && vis[num]) num++;
        ans[i] = num;
        num++;
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