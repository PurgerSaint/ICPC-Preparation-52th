#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

mt19937_64 rng(time(0)); 
ll rnd(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

int sum(ll t) {
    ll ans = 0;
    while (t >= 1) {
        ans += t % 10;
        t /= 10;
    }
    return ans;
}

int main() {
    ios;
    int cnt = 0;
    while (true) {
        ll n = rnd(1, 10000);
        if (n % 10 != 9) continue;
        cnt++;
        ll x = n / 2, y = x + (n % 2 > 0);
        ll x1, y1;
        for (ll i = max(x, y); i <= n; i++) {
            x1 = sum(i), y1 = sum(n - i);
            if (abs(x1 - y1) <= 1) {
                x = i, y = n - i;
                break;
            }
        }
        if (abs(x1 - y1) > 1) {
            cout << "Wrong Test " << cnt << "\n";
            cout << "n:" << n << "\n";
            cout << "x:" << x << " y:" << y << "\n";
            cout << "sum1:" << x1 << " sum2:" << y1;
            break;
        }
        cout << "Test " << cnt << " OK, n:" << n;
        cout << " x:" << x << " y:" << y << "\n";
    }
    return 0;
}
 