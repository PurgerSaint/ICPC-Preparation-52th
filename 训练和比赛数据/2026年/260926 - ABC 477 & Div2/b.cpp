#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

ll solve() {
    
}

int main() {
    ios;
    ll t; cin >> t;
    while (t >= 1) {
        cout << (t % 10);
        t /= 10;
    }
    return 0;
    int t1; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}