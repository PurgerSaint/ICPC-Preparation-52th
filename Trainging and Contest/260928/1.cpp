#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

bool solve() {
    string s, t; cin >> s >> t;
    vector<pair<char, int>> a, b;
    for (char c: s) {
        if (a.empty() || a.back().first != c) a.push_back({c, 0});
        a.back().second++;
    }
    for (char c: t) {
        if (b.empty() || b.back().first != c) b.push_back({c, 0});
        b.back().second++;
    }
    if (a.size() != b.size()) return 0;
    int sz = a.size();
    for (int i = 0; i < sz; i++) {
        auto& [c1, cnt_a] = a[i];
        auto& [c2, cnt_b] = b[i];
        if (c1 != c2) return 0;
        if (cnt_b < cnt_a || cnt_b > 2 * cnt_a) return 0;
    }
    return 1;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        if (t) cout << "\n";
    }
    return 0;
}