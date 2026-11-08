#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    ll x; cin >> x;
    vector<int> a;
    while (x > 0) {
        a.push_back(x & 1);
        x >>= 1;
    }
    int n = a.size();
    int cnt = 0;
    auto change = [&](int i) -> void {
        if (i == n) a.push_back(0);
        a[i - cnt] = -1;
        for (int j = i - cnt + 1; j < i; j++)
            a[j] = 0;
        a[i] = 1;
        cnt = 1;
    };
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) cnt++;
        else {
            if (cnt > 1) {
                change(i);
                continue;
            }
            cnt = 0;
        }
    }
    if (cnt > 1) change(n);
    n = a.size();
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << (i + 1 < n ? " " : "");
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