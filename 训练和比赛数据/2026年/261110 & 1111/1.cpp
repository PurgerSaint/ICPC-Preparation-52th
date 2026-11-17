#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n; ll k; cin >> n >> k;
    vector<vector<bool>> mp(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            mp[i][j] = t;
        }
    ll cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mp[i][j] != mp[(n - 1) - i][(n - 1) - j])
                cnt++;
    // cout << cnt << " " << k << "\n";
    k -= cnt / 2;
    return k >= 0 && (k % 2 == 0 || n % 2 == 1);
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