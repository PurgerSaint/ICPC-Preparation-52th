#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n + 1);
    vector<int> in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        int len = r - l + 1;
        vector<int> loc(len);
        for (int& t: loc) cin >> t;
        for (int j = len - 1; j - 1 >= 0; j--) {
            int& u = loc[j];
            int& v = loc[j - 1];
            mp[u].push_back(v);
            in[v]++;
        }
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
        if (!in[i]) pq.push(i);

    vector<int> ans(n + 1, 0);
    int cnt = 0, num = n;
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        ans[u] = num--;
        cnt++;
        for (int& v: mp[u]) {
            in[v]--;
            if (!in[v]) pq.push(v);
        }
    }
    if (cnt < n) {
        cout << -1;
        return;
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
}