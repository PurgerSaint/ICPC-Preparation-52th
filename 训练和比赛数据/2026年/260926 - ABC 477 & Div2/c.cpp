#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

ll solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == k) return max(a[k], a[1]);
    if (k == 1) return accumulate(range(a), 0LL);
    ll sum = 0;
    for (int i = k; i <= n - k + 1; i++) sum += a[i];
    for (int i = min(k - 1, n - k + 1); i >= 1; i--) sum += max(a[i], a[n - i + 1]);
    return sum;
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