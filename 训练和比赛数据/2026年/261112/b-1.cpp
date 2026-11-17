#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    vector<pair<char, int>> cnt;
    for (char c: s) {
        if (cnt.empty() || c != cnt.back().first) cnt.push_back({c, 1});
        else cnt.back().second++;
    }
    return n - cnt.size() + (s[0] == 'B');
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