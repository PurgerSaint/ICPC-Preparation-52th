#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; ll k; cin >> n >> k;
    if (k % 2) {
        for (int i = 1; i < n; i++)
            cout << n << " ";
        cout << (n - 1);
    } else {
        for (int i = 1; i < n - 1; i++)
            cout << (n - 1) << " ";
        if (n > 1) cout << n << " ";
        cout << (n - 1);
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