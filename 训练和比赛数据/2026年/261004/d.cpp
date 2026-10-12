#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    ll x, y, s, m, k; cin >> x >> y >> s >> m >> k;
    int n; cin >> n;

    vector<ll> a(n);
    for (ll& t: a) cin >> t; 

    vector<ll> p1, p2;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        t ? p1.push_back(a[i]) : p2.push_back(a[i]);
    }

    sort(range(p1), greater<ll>());
    sort(range(p2), greater<ll>());
    int m1 = p1.size(), m2 = p2.size();

    vector<ll> s1(m1 + 1, 0), s2(m2 + 1, 0);
    for (int i = 1; i <= m1; i++) s1[i] = s1[i - 1] + p1[i - 1];
    for (int i = 1; i <= m2; i++) s2[i] = s2[i - 1] + p2[i - 1];

    // cout << m1 << " " << m2 << "\n";
    ll ans = 0, get = 0, less = s;
    const ll b1 = k * x;
    for (int i = 0; i <= m1; i++) {
        // ll lm = s - (i - 1) * (b1 + y), la = m - (i - 1) * k;
        // if (lm >= 0 && la >= 0)
        //    ans = max(ans, s1[i - 1] + s2[min(max(lm, 0LL) / b1, min(1LL * m2, max(la, 0LL) / k))]);
        
        ll lm = s - i * (b1 + y), la = m - i * k;
        if (lm >= 0 && la >= 0)
            ans = max(ans, s1[i] + s2[min(max(lm, 0LL) / b1, min(1LL * m2, max(la, 0LL) / k))]);
    }

    cout << ans;

    return 0;
}