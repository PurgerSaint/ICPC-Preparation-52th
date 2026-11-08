#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    sort(range(a));
    ll ans = n + (n * (n - 1)) / 2;
    vector<int> cnt(n, 0);
    int t = 0;
    for (int i = 0; i < n; i++) {
        cnt[i] += binary_search(range(cnt), a[i] + 1);
        cnt[i] += binary_search(range(cnt), a[i] + 2);
        cnt[i] += binary_search(range(cnt), a[i] + 3);
        if (cnt[i] >= 2) t++;
    }
    
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