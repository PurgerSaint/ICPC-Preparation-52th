#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int solve() {
    int n, k; cin >> n >> k;
    vector<bool> vis(n + 1, 0);
    vector<int> a(n);
    for (int& t: a) {
        cin >> t;
        vis[t] = 1;
    }
    int mex = 0;
    while (vis[mex]) mex++;
    return min(mex, k-1);
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