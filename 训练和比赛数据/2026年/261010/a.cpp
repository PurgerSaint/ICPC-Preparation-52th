#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll dis(const int& x, const int& y, const int& a, const int& b) {
    return sqrt(1LL * abs(x - a) * abs(x - a) + 1LL * abs(y - b) * abs(y - b));
}

int solve() {
    int x, y; cin >> x >> y;
    int ans = 0;
    int a = 0, b = 0;
    if (x == a && y == b) return 0;
    while (true) {
        ans++;
        int x1 = a, y1 = b + 1;
        if ((x1 == x || x1 + 1 == x) && y1 == y) return ans;
        x1++;

        int x2 = a, y2 = b - 1;
        if ((x2 == x || x2 + 1 == x) && y2 == y) return ans;
        x2++;

        ll r1 = dis(x1, y1, x, y), r2 = dis(x2, y2, x, y);
        if (r1 < r2) a = x1, b = y1;
        else a = x2, b = y2;
        if (a > 1000 || b > 1000) break;
    }
    return -1;
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