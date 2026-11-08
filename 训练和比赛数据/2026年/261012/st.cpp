#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    ll n; cin >> n;
    vector<bool> f(n + 1, 0);
    int cnt = 0;
    for (ll i = 2; i <= n; i++) {
        if (f[i]) continue;
        cnt++;
        cout << i << " ";
        for (ll j = 2; i * j <= n; j++)
            f[i * j] = 1;
    }
    cout << "\n" << "cnt:" << cnt;
    return 0;
}