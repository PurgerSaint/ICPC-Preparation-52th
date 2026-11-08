#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<int> d(n);
    for (int& t: d) cin >> t;
    vector<int> a(n);
    a[0] = d[0];
    for (int i = 1; i < n; i++) {
        if (d[i] > 0 && a[i - 1] >= d[i]) {
            cout << -1;
            return;
        }
        a[i] = a[i - 1] + d[i];
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << (i + 1 < n ? " " : "");
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