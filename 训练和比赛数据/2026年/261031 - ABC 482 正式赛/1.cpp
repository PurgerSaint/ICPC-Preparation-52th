#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> a(26, 0), b(26, 0);
    for (char c: s) a[c - 'a']++;
    for (char c: t) b[c - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (a[i] == 0 || b[i] == 0) continue;
        if (b[i] <= a[i]) {
            n -= b[i], a[i] -= b[i];
        } else if (b[i] > a[i]) {
            a[i] = 0, n -= a[i];
        }
        m -= b[i];
    }
    return m == 0 && n == 3 && a['s' - 'a'] == 1 && a['i' - 'a'] == 1 && a['x' - 'a'] == 1;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        if (t) cout << "\n";
    }
    return 0;
}