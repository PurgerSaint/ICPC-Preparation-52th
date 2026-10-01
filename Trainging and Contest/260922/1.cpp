#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

string solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(range(a));
    ll sum = accumulate(range(a), 0LL);
    bool tom = sum % 2 > 0;
    ll mx = a[n - 1], mx_cnt = a.end() - lower_bound(range(a), a[n - 1]);
    ll mn = a[0];
    if (mx - mn > k + 1) return "Jerry";
    if (mx - mn > k && mx_cnt > 1) return "Jerry";
    return tom ? "Tom" : "Jerry";
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