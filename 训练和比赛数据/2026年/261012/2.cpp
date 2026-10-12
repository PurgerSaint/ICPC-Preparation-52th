#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n);
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        a[i + 1] = b[i];
    }
    a[1] = a[2];
    for (int i = 2; i < n; i++) {
        if (a[i] > b[i]) {
            a[i] = b[i];
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << (i < n ? " " : "");
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