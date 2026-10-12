#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cnt[t]++;
    }
    int mex = 0, num = 0;
    for (int i = 0; i <= n + 1; i++) {
        // cout << i << " " << cnt[i] << "\n";
        if (cnt[i] + 1 < 2 * k) return 0;
        if (cnt[i] + 1 == 2 * k) return 1;
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