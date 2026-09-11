#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n + 1, 0);
    bool f = 1;
    vector<int> num(n + 1, 0);
    for (int i = 0; i <= n; i++)
        num[i] = i;
    vector<vector<int>> p(m);
    for (vector<int>& b: p) {
        int l, r; cin >> l >> r;
        int sz = r - l + 1;
        for (int i = 0; i < sz; i++) {
            int t; cin >> t;
            b.push_back(t);
        }
    }
    sort(range(p), [](vector<int>& x, vector<int>& y){
        return x.size() > y.size();
    });
    for (vector<int>& loc: p) {
        int sz = loc.size();
        if (!f || sz <= 1) continue;
        for (int k = sz - 1; k >= 0; k--) {
            int& j = loc[k];
            if (k > 0 && ((a[j] == 0 && a[loc[k - 1]] > 0) || (a[j] > 0 && a[loc[k - 1]] > 0 && a[loc[k - 1]] >= a[j]))) {
                // cout << j << " " << loc[k - 1] << " ";
                // cout << a[j] << " " << a[loc[k - 1]] << "\n";
                f = 0;
                break;
            }
            // cout << j << " " << a[j] << "\n";
            if (a[j] != 0) continue;
            a[j] = num.back();
            num.pop_back();
        }
    } 
    if (!f) {
        cout << -1;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cout << num.back();
            num.pop_back();
        } else cout << a[i];
        if (i < n) cout << " ";
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