#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<int>> idx(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        idx[a].push_back(b);
    }
    vector<int> cnt(n + 1, 0);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = i;
        cnt[i] = idx[i].size();
    }
    sort(range(b), [&](int& x, int& y){
        if (cnt[x] == cnt[y]) return x < y;
        return cnt[x] > cnt[y]; 
    });
    vector<int> g(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int ans = b[0] == i ? b[1] : b[0];
        for (int& b: idx[i]) {
            g[b]++;
            if ((cnt[b] + g[b]) > (cnt[ans] + g[ans]) || (cnt[b] + g[b] == cnt[ans] + g[ans] && b < ans))
                ans = b;
        }
        cout << ans << (i < n ? "\n" : "");
        for (int& b: idx[i])    g[b]--;
    }
    return 0;
}