#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];

    int cnt = 1;
    string ans = "";
    ans += a[0][0];
    for (int i = 0; i < n - 1; i++) {
        if (a[0][i + 1] == a[1][i]) {
            ans += a[0][i + 1];
            cnt++;
        } else if (a[0][i + 1] == '0') {
            ans += a[0][i + 1];
            cnt = 1;
        } else if (a[1][i] == '0') {
            for (int j = i; j < n; j++)
                ans += a[1][j];
            break;
        }
        if (i + 1 == n - 1) ans += a[1][n - 1];
    }
    cout << ans << "\n" << cnt;
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