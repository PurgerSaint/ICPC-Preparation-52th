#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int& t: a) {
        cin >> t; s += t;
    }
    if (s == n) return -1;
    for (int i = 1; i + 1 < n; i++)
        if (a[i] > 1) return s - 1;
    return s - (n - 1);
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