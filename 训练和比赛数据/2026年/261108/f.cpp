#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios;
    ll x, y, l, r, v; cin >> x >> y >> l >> r >> v;
    ll l1 = max(l, x), r1 = min(r, y);
    ll a = (r - l) * (y - x), b = v  * (r1 - l1);
    ll g = gcd(a, b);
    cout << (a / g) << "/" << (b / g);
    return 0;
}