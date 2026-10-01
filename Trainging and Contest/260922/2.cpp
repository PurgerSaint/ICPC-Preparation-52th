#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

string solve() {
    int n; cin >> n;
    string s; cin >> s;
    int b_cnt = count(range(s), 'B');
    if (s[n - 1] == s[n - 2] && s[n - 1] == 'A') return "Alice";
    if (s[0] == s[n - 1] && s[n - 1] == 'A') return "Alice";
    if (b_cnt == 1 && s[n - 1] == 'B') return "Alice";
    return "Bob";
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