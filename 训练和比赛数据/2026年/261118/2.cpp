#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> loc(27);
    for (int i = 0; i < n; i++) 
        loc[s[i] == '?' ? 26 : (s[i] - 'a')].push_back(i);

    int l = -1;
    for (char c: t) {
        auto it1 = upper_bound(range(loc[c - 'a']), l);
        auto it2 = upper_bound(range(loc[26]), l);
        int next = l;
        if (it1 == loc[c - 'a'].end()) {
            if (it2 == loc[26].end()) {
                cout << "NO";
                return;
            }
            next = *it2;
            s[next] = c;
        } else {
            next = *it1;
            if (it2 != loc[26].end() && *it2 < *it1) {
                next = *it2; s[next] = c;
            }
        }
        l = next;
    }
    for (int& i: loc[26])
        if (s[i] == '?') s[i] = 'a';
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