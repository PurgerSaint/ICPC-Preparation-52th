#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

struct state {
    int mx, mn;
    vector<int> p;
    state(): mx(0), mn(INT_MAX) {}
};

ll solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int& t: a) cin >> t;
    for (int& t: b) cin >> t;
    for (int& t: c) cin >> t;
    vector<vector<bool>> f(n + 1, vector<bool>(4, 0));
    vector<vector<int>> x(3);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[a[i]][1] = 1;
        f[b[i]][2] = 1;
        f[c[i]][3] = 1;

        if (f[a[i]][1] == f[a[i]][2] && (x[0].empty() || x[0].back() != a[i])) {
            x[0].push_back(a[i]);
        }
        if (f[a[i]][1] == f[a[i]][3] && (x[2].empty() || x[2].back() != a[i])) {
            x[2].push_back(a[i]);
        }
        if (f[b[i]][2] == f[b[i]][1] && (x[0].empty() || x[0].back() != b[i])) {
            x[0].push_back(b[i]);
        }
        if (f[b[i]][2] == f[b[i]][3] && (x[1].empty() || x[1].back() != b[i])) {
            x[1].push_back(b[i]);
        }
        if (f[c[i]][3] == f[c[i]][1] && (x[2].empty() || x[2].back() != c[i])) {
            x[2].push_back(c[i]);
        }
        if (f[c[i]][3] == f[c[i]][2] && (x[1].empty() || x[1].back() != c[i])) {
            x[1].push_back(c[i]);
        }

        ans += (x[0].size() == i + 1 || x[1].size() == i + 1 || x[2].size() == i + 1);
    }
    return ans;
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