#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    if (n == 1) {
        cout << "1";
        return 0;
    }
    sort(range(a));


    return 0;
}