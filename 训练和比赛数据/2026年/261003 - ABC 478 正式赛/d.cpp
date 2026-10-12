#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, q; cin >> n >> q;
    vector<vector<vector<int>>> diff(n + 2, vector<vector<int>>(2));
    for (int i = 1; i <= q; i++) {
        int l, r, x; cin >> l >> r >> x;
        diff[l][0].push_back(x);
        diff[r + 1][1].push_back(x);
    }
    
    int dis_cnt = 0;
    vector<int> cnt(q + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int& x: diff[i][1]) {
            cnt[x]--;
            if (cnt[x] == 0) dis_cnt--;
        }
        for (int& x: diff[i][0]) {
            if (cnt[x] == 0) dis_cnt++;
            cnt[x]++;
        }
        cout << dis_cnt << (i < n ? " " : "");
    }
    return 0;
}