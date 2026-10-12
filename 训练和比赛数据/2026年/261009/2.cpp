#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    ll n; cin >> n;
    ll x = n / 2, y = (n + 1) / 2;
    if (n % 10 != 9) {
        cout << x << " " << y;
        return;
    }
    string s = to_string(n);
    int pos = -1;
    int m = s.length();
    for (int i = 0; i < m; i++)
        if ((s[i] - '0') % 2 == 0) pos = i;
    ll t = 0;
    for (int i = 0; i <= pos; i++)
        t = t * 10 + (s[i] - '0');
    string x_s = "", y_s = "";
    if (t) x_s += to_string(t / 2), y_s = x_s;
    for (int i = pos + 1; i < m; i++) {
        int c = s[i] - '0';
        char c1 = '0' + (c + (i % 2 == 0)) / 2;
        if (!x_s.empty() || c1 != '0') x_s += c1;
        char c2 = '0' + (c + (i % 2 > 0)) / 2;
        if (!y_s.empty() || c2 != '0') y_s += c2;
    }
    cout << x_s << " " << y_s;
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