#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

string solve() {
    int n, m; cin >> n >> m;
    string s, c; cin >> s;
    vector<int> ind(m);
    for (int& t: ind) cin >> t;
    cin >> c;
    sort(range(ind));
    sort(range(c), greater<char>());
    vector<bool> vis(n, 0);
    for (int& i: ind) {
        i--;
        if (vis[i] && c.back() >= s[i]) continue;
        s[i] = c.back();
        c.pop_back();
        vis[i] = 1;
    }
    return s;
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