#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') a.push_back(i);
        else b.push_back(i);
    }
    int cnt_a = a.size(), cnt_b = b.size();
    if (cnt_a == 1) return 0;
    if (cnt_a == 2) return 1;
    return a.back() - a[0];
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