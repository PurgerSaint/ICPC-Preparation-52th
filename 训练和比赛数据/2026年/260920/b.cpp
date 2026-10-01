#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        int r = n - 1, c = m - 1;
        int ans = 0;
        if (r && c) {
            ans = 2 * r + 2 * c;
            if (1 < y && y < m) ans += 2 * r;
            if (1 < x && x < n) ans += 2 * c;
        }
        cout << ans << (t ? "\n" : "");
    }
    return 0;
}