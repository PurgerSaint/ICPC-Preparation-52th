#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

void solve() {
    int n, k; cin >> n >> k;
    if (n == 1) {
        cout << "1" << "\n" << "1";
        return;
    }
    if (k == 1 || k == n) {
        cout << -1;
        return;
    }
    if (n == 3 || k == 2) {
        cout << 3 << "\n" << "1 2 3";
        return;
    } 
    if (k == n - 1) {
        cout << 3 << "\n" << 1 << " " << (n - 1) << " " << n;
        return;
    }
    if (k % 2) {
        cout << 5 << "\n";
        cout << 1 << " " << 2 << " " << k << " " << (k + 1) << " " << (k + 2);
        return;
    }
    cout << 5 << "\n";
    cout << 1 << " " << 2 << " " << (k - 1) << " " << (k + 2) << " " << (k + 3);
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