#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    map<ll, vector<int>> loc;
    for (int i = 1; i <= n; i++) {
        ll t; cin >> t;
        loc[t].push_back(i);
    }
    ll ans = 0;
    for (auto& [_, p]: loc) {
        int sz = p.size();
        if (sz % 2 == 0) continue;
        ans += p[sz / 2];
    }
    cout << ans;
    return 0;
}