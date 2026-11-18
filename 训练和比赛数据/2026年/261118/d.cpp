#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n; cin >> n;
    vector<pair<ll, ll>> b(n);
    for (auto& [a, m]: b) cin >> a >> m;
    sort(range(b), [](pair<ll, ll>& x, pair<ll, ll>& y){
        if (x.second == y.second) return x.first > y.first;
        return x.second > y.second;
    });
    auto& [am, mx] = b[0];
    if (am == 0) am = mx;
    for (auto it = b.begin() + 1; it != b.end(); it++) {
        auto& [a, m] = *it;
        if (am % m != a % m || mx % m != 0) return 0;
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