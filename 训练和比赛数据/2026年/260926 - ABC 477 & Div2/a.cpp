#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

vector<ll> gk;

ll solve() {
    int n, k; cin >> n >> k;
    return 2 * (k - 1) + gk[n - (k - 1)];
}

int main() {
    ios;
    int t; cin >> t;
    gk.push_back(1);
    for (int i = 1; i <= 30; i++)
        gk.push_back(gk.back() * 2);
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}