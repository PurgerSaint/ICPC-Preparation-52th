#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<ll> bk;
    vector<vector<ll>> buk(9);
    for (ll& i: a) {
        int step = 0;
        ll t = i;
        while (true) {
            if (t == 4) {
                buk[step % 8].push_back(i);
                break;
            }
            if (t == 1) {
                buk[8].push_back(i);
                break;
            }
            ll res = 0;
            while (t >= 1) {
                ll l = t % 10;
                res += l * l;
                t /= 10;
            }
            step++;
            t = res;
        }
    } 
    ll ans = 0;
    for (vector<ll>& p: buk) {
        int sz = p.size();
        ans += sz * (sz - 1) / 2;
    }
    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}