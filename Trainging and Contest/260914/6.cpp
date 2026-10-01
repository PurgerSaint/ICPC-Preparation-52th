#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, q; ll x; cin >> n >> q >> x;
    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i] - x);
    }
    sort(range(a));
    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }
    while (q--) {
        ll k; cin >> k;
        auto it = upper_bound(range(s), k);
        cout << (s.end() - it) << (q ? "\n" : "");
    }
    return 0;
}