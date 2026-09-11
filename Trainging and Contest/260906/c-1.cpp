#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n + 1);
    vector<int> in(n + 1, 0);
    bool f = 0;
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        int sz = r - l + 1;
        vector<int> loc(sz);
        for (int& t: loc) cin >> t;
        for (int j = sz - 1; j - 1 >= 0; j--) {
            int& u = loc[j];
            int& v = loc[j - 1];
            mp[u].push_back(v);
            in[v]++;
        }
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) q.push(i);
    }
    int num = n;
    int cnt = 0;
    vector<int> ans(n + 1, 0);
    while (!q.empty()) {
        int u = q.top(); q.pop();
        ans[u] = num--;
        cnt++;

        for (int& v: mp[u]) {
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
    if (cnt < n) cout << -1;
    else {
        for (int i = 1; i <= n; i++)
            cout << ans[i] << (i < n ? " " : "");
    }
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