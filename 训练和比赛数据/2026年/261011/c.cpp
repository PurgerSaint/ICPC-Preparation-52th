#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

vector<pair<ll, ll>> d;
ll w; int n;

ll dfs(int i, ll s) {
    if (i >= n || s <= 0) return 0;
    auto& [a, b] = d[i];
    ll ans = dfs(i + 1, s);
    if (s >= b) ans = max(ans, a + dfs(i + 1, s - b));
    return ans;
}

int main() {
    ios;
    cin >> n;
    cin >> w;
    d = vector<pair<ll, ll>>(n);
    for (auto& [l, r]: d) cin >> l >> r;
    sort(range(d), [](pair<ll, ll>& x, pair<ll, ll>& y){
        return x.first > y.first;
    });

    auto& [a, b] = d[0];
    ll ans = dfs(1, w);
    if (w >= b) ans = max(ans, a + dfs(1, w - b));

    cout << ans;
    return 0;
}