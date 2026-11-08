#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; ll s; cin >> n >> s;
    vector<ll> cnt(3, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll sum = 0 * cnt[0] + 1 * cnt[1] + 2 * cnt[2];
    if (sum == s || s >= sum + 2) {
        cout << -1;
        return;
    }
    for (int i = 0; i < cnt[0]; i++) cout << 0 << " ";
    for (int i = 0; i < cnt[2]; i++) cout << 2 << " ";
    for (int i = 0; i < cnt[1]; i++) cout << 1 << " ";
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