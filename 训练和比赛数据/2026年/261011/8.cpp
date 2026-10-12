#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t; a[t] = i;
    }
    for (int i = 1; i <= n; i++) {
        int t; cin >> t; b[t] = i;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (b[i] >= a[i]) continue;
        // if (b[i] > a[i]) ans = max(ans, n - (b[i] - a[i]));
        // else 
        ans = max(ans, a[i] - b[i] + 1);
    }
    cout << ans;
    return 0;
}