#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<pair<string, int>> a(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first; mp[a[i].first] = i;
    }
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (mp.count(s)) a[mp[s]].second++;
        else {
            int sz = s.length();
            vector<int> match;
            for (int j = 0; j < sz; j++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == s[j]) continue;
                    char h = s[j]; s[j] = c;
                    if (mp.count(s)) match.push_back(mp[s]);
                    s[j] = h;
                }
            }
            if ((int)match.size() > 1 || match.empty()) continue;
            a[match[0]].second++;
        }
    }
    for (auto it = a.begin(); it != a.end(); it++) {
        auto& [_, cnt] = *it;
        cout << cnt;
        if (next(it) != a.end()) cout << "\n";
    }
    return 0;
}