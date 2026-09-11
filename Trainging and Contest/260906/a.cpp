#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

string solve() {
    int n; cin >> n;

    vector<pair<char, ll>> p;
    map<ll, vector<int>> t, f;
    for (int i = 0; i < n; i++) {
        char c; ll x; cin >> c >> x;
        p.emplace_back(c, x);
        if (c == 'T') t[x].push_back(i);
        else f[x].push_back(i);
    }
    for (auto& [_, p]: t) sort(range(p), greater<int>());
    for (auto& [_, p]: f) sort(range(p), greater<int>());
    map<ll, vector<int>> cnt;
    map<int, int> ot;
    string ans = "";
    for (int i = 0; i < n ; i++) {
        auto& [c, x] = p[i];
        if (c == '+') {
            if (cnt.count(x) && !cnt[x].empty() && (f.count(x) && f[x].back() > i)) {
                while (!cnt[x].empty()) {
                    int loc = cnt[x].back(); cnt[x].pop_back();
                    ot[loc]++;
                }
            }
            cnt[x].push_back(i);
        } else if (c == 'T') {
            t[x].pop_back();
            if (!cnt[x].empty() && (f.count(x) && t.count(x) && !f[x].empty() && !t[x].empty() && f[x].back() < t[x].back())) {
                while (!cnt[x].empty()) {
                    int loc = cnt[x].back(); cnt[x].pop_back();
                    ot[loc]++;
                }
            }
        } else {
            f[x].pop_back();
        }
    }
    for (int i = 0; i < n; i++) {
        auto& [c, x] = p[i];
        if (c == '+') {
            ans += '+';
        } else ans += '?';
        while (ot.count(i) && ot[i] > 0) {
            ans += '-';
            ot[i]--;
        }
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