#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    vector<bool> f(n - 1, 0);
    int cnt = 0;

    for (int i = 0; i + 1 < n; i++) {
        int& x = a[i];
        int& y = a[i + 1];
        if (x == k || y == k) {
            if (x == k && y != k && i > 0 && f[i - 1]) continue;
            f[i] = 1;
            cnt++;
        }
        if (min(x, y) < k && k < max(x, y)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}