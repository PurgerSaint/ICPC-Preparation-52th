#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, v; cin >> n >> v;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (i > v) break;
        for (int j = i + 1; j < n; j++) {
            if (i + j > v) break;
            for (int k = j + 1; k <= n; k++) {
                if (i + j + k > v) break;
                if (a[i] + a[j] + a[k] > ans)
                    ans = a[i] + a[j] + a[k];
            }
        }
    }
    cout << ans;
    return 0;
}