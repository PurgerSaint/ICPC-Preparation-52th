#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int dfs(int l, int r) {
    if (l > r) return -1;
    cout << "? " << l << " " << r << endl;
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;
    int res = dfs(1, n);
    if (res == 0 || res == n) {
        cout << "! NO" << endl;
        return;
    }
    if (dfs(1, res) < res) {
        cout << "! YES" << endl;
        return;
    }
    cout << "! NO" << endl;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}