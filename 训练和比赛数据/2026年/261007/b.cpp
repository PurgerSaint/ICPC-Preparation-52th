#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<int> memo;
    vector<bool> f(n + 1, 1);
    string s; cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '3') f[i] = 0;
        else if (s[i] == '1') memo.push_back(i);
        else if (!memo.empty()) {
            int t = memo.back(); memo.pop_back();
            f[t] = 0;
        } else f[i] = 0;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (f[i]) ans.push_back(i);

    cout << ans.size() << "\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << (it + 1 != ans.end() ? " " : "");
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