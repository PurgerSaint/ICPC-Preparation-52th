#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int n, k; ll x;
vector<ll> a;

bool dfs(ll t, int cnt, vector<bool> vis) {
    if (t <= 0 || cnt > k) return 0;
    bool ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[1] = 1;
        if (a[i] == t && cnt == k - 1) return 1;
        ans = ans || dfs(t ^ a[i], cnt + 1, vis);
        vis[i] = 0;
    }
    return ans;
}

int main() {
    ios;
    cin >> n >> k >> x;

    return 0;
}