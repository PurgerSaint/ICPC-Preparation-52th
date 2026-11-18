#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;

    ld l = 0, r = 1e5;
    for (int cnt = 0; cnt < 100; cnt++) {
        ld mid = (l + r) / 2;

        ld s = 0;
        for (ll& t: a) {
            ld x = mid * t;
            s += 1 - 1 / (1 + x);
        }

        (s > k ? r : l) = mid;
    }
    cout << fixed << setprecision(12);
    for (int i = 0; i < n; i++) {
        ld x = l * a[i];
        cout << (1 - 1 / (1 + l * a[i])) << (i + 1 < n ? "\n" : "");
    }
    return 0;
}