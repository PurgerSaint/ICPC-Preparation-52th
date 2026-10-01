#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

bool solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    ll st = a[k - 1];
    sort(range(a));
    a.erase(unique(range(a)), a.end());
    ll wa = 1, ed = a[n - 1];
    auto start_it = lower_bound(range(a), st);
    for (auto it = start_it; it + 1 != a.end(); it++) {
        if (*(it + 1) - *it > st) {
            return 0;
        }
    }
    return 1;
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