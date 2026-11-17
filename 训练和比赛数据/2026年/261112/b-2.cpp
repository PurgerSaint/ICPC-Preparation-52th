#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    char t = 'R';
    for (char c: s) {
        if (c != t) ans++, t = c;
        t = (t == 'B' ? 'R' : 'B');
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