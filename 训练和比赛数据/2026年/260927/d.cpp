#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    ll n; cin >> n;
    if (n % 2) cout << -1;
    else cout << -1 << " " << 1 << " " << n / 2;
    return 0;
}