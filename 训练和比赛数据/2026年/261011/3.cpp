#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i + n] = a[i];
    }
    int cnt = 1;
    for (int i = 1; i < 2 * n; i++) {
        if (a[i] >= a[i - 1]) cnt++;
        else cnt = 1;
        if (cnt == n - 1) return 1;
    }
    return 0;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        if (t) cout << "\n";
    }
    return 0;
}