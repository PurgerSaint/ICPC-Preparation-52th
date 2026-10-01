#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

ll solve() {
    int n; char c; cin >> n >> c;
    string s; cin >> s;
    int cnt = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        if (s[i] == s[n - i - 1]) continue;
        // cout << s[i] << " " << s[n - i - 1] << "\n";
        cnt += (s[i] != c) + (s[n - i - 1] != c);
    }
    return cnt;
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