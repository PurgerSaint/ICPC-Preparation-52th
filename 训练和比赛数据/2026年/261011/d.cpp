#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, q; cin >> n >> q;
    vector<ll> l(n + 1), r(n + 1);
    for (int i = 2; i <= n; i++) cin >> l[i];
    for (int i = 1; i < n; i++) cin >> r[i];

    r[n] = r[n - 1];
    l[1] = l[2];

    vector<ll> lm(n + 1, 0), rm(n + 1, 0);
    lm[n] = l[n];
    for (int i = n - 1; i >= 1; i--)
        lm[i] = min(lm[i + 1], l[i]);
    rm[1] = r[1];
    for (int i = 2; i <= n; i++)
        rm[i] = min(rm[i - 1], r[i]);

    while (q--) {
        ll i, j; cin >> i >> j;

        ll dis = 0;
        if (i > j) {
            dis = min(l[i], r[i] + lm[i]);
        } else if (i < j) {
            dis = min(r[i], l[i] + rm[i]);
        }
        cout << dis << (q ? "\n" : "");
    }
    return 0;
}