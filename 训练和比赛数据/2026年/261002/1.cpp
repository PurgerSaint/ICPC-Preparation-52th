#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<vector<int>> ans;
    ans.push_back({});
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] == 1) {
            vector<int>& p = ans.back();
            if (p.empty() || p.back() + 1 == i) p.push_back(i);
            else ans.push_back({i});
        }
    }
    if (!ans[0].empty()) {
        sort(range(ans), [](vector<int>& x, vector<int>& y){ return x.size() > y.size(); });
        vector<int>& p = ans[0];
        if ((int)p.size() == 1) cout << p[0] << " " << p[0];
        else cout << p[0] << " " << p.back();
        return;
    }
    cout << 0;
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