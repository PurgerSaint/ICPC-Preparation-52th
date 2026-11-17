#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(range(a));
    vector<pair<ll, int>> b;
    for (ll& t: a) {
        if (b.empty() || b.back().first != t) b.push_back({t, 1});
        else b.back().second++;
    }
    vector<ll> ans;
    int cnt = b.size();
    for (int j = 0; j < b.size(); j++)
        ans.push_back(b[j].first), b[j].second--;
    for (int j = 0; j < b.size(); j++) {
        while (b[j].second > 1)
            ans.push_back(b[j].first), b[j].second--;
    }
    for (int j = b.size() - 1; j >= 0; j--) {
        if (b[j].second == 0) continue;
        cnt++, ans.push_back(b[j].first);
    }
    cout << cnt << "\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << (*it) << (it + 1 != ans.end() ? " " : "");
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}