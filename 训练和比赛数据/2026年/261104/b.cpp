#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    sort(range(a));
    vector<pair<int, int>> b;
    for (int& t: a) {
        bool f = 0;
        for (auto it = b.begin(); it != b.end(); it++) {
            auto& [x, cnt] = *it;
            if (t % x == 0) cnt++, f = 1;
        }
        if (f) continue;
        b.push_back({t, 1});
    }
    sort(range(b), [](pair<int, int>& x, pair<int, int>& y){
        return x.second > y.second;
    });
    return n - b[0].second;
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