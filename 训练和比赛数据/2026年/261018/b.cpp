#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int a, b, k; cin >> a >> b >> k;
    ll t = a / b;
    a = a % b;
    ll ans = 1LL * (a * pow(10, k)) / b;
    cout << t << " " << ans;
    return 0;
}