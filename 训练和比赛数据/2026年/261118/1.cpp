#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct state {
    char c;
    int l, r;
};

int solve() {
    string s; cin >> s;
    vector<state> zip;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (zip.empty() || zip.back().c != s[i]) {
            if (!zip.empty()) zip.back().r = i - 1;
            zip.push_back({s[i], i, i});
        }
    }
    zip.back().r = n - 1;
    int ans = zip.size();
    for (auto& [c, l, r]: zip) {
        if (c == '1') continue;
        if (r + 1 < n && s[r + 1] == '1') {
            ans--; break;
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