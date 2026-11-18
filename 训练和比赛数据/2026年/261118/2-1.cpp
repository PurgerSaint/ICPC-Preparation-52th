#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    string s, t; cin >> s >> t;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        if (t.empty()) {
            if (*it == '?') *it = 'a';
            continue;
        }
        if (*it != '?' && *it != t.back()) continue;
        if (*it == '?') *it = t.back();
        t.pop_back();
    }
    if (!t.empty()) {
        cout << "NO"; return;
    }
    cout << "YES\n" << s;
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