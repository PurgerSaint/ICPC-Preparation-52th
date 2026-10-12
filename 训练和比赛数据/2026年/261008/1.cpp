#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

string solve() {
    int n; cin >> n;
    int k; cin >> k;
    string s; cin >> s;
    if (k % 2 == 0) {
        sort(range(s));
        return s;
    }
    string x = "", y = "";
    for (int i = 1; i <= n; i++) {
        if (i % 2) x += s[i - 1];
        else y += s[i - 1];
    }
    sort(range(x));
    sort(range(y));
    string ans = "";
    int sz1 = x.size(), sz2 = y.size();
    for (int i = 0; i < sz1; i++) {
        ans += x[i];
        if (i < sz2) ans += y[i];
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