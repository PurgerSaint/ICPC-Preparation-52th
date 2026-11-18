#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

vector<ll> solve() {
    int n; cin >> n;
    vector<int> x(n - 1);
    for (int& t: x) cin >> t;
    vector<ll> ans(n);
    ans[0] = 501;
    for (int i = 1; i < n; i++)
        ans[i] = ans[i - 1] + x[i - 1];
    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        vector<ll> ans = solve();
        int n = ans.size();
        for (int i = 0; i < n; i++)
            cout << ans[i] << (i < n - 1 ? " " : "");
        if (t) cout << "\n";
    }
    return 0;
}