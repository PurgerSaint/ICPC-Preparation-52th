#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, s, t; cin >> n >> s >> t;
    if (s >= t) cout << (min(s, t) + (abs(t - s) + 1) / 2);
    else {
        ll ans = (t + (n - t + s + 1) / 2) % n;
        if (!ans) ans = n;
        cout << ans;
    }
    return 0;
}