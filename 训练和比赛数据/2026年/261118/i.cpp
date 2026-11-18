#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

string solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
        (s[i] == '1' ? a : b).push_back(i);
    reverse(range(b));
    int cnt = k / 2;
    for (int i = 0; i < min(cnt, (int)min(a.size(), b.size())); i++) {
        if (a[i] > b[i]) break;
        swap(s[a[i]], s[b[i]]);
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