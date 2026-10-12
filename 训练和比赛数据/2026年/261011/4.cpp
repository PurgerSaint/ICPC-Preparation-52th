#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0;
    vector<pair<char, int>> c;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i > 0 && s[i - 1] != s[i]) cnt++;
            if (i + 1 < n && s[i + 1] != s[i]) cnt++;
        }
        if (c.empty() || c.back().first != s[i]) c.push_back({s[i], 1});
        else c.back().second++;
    }
    if (cnt >= 3) return 0;
    else if (cnt == 0) return 2;

    for (auto& [ch, ct]: c)
        if (ct >= 3) return 1;
    
    // 1011 1101
    if (cnt == 2 && (c.back().second == 2 || c[0].second == 2)) return 1;

    return 2;
}
// 101111 0110 
// 0111 1110 1100

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}