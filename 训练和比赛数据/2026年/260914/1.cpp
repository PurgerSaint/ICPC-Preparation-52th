#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

ll solve() {
    int n; ll c; cin >> n >> c;
    vector<ll> a(n);
    for (ll& t: a) {
        cin >> t;
        t -= c;
    }
    sort(range(a));
    for (int i = 0; i < n / 2; i++) {
        a[i] = max(a[i], 0LL);
    }
    return accumulate(range(a), 0LL);

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