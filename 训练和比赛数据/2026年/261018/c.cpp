#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, p; cin >> n >> p;
    int mx = 0;
    vector<pair<int, int>> e(n);
    for (auto& [l, r]: e) {
        cin >> l >> r;
        if (l > r) swap(l, r);
    }
    sort(range(e));
    map<int, int> d;
    int cnt = 0;
    for (auto& [l, r]: e) {
        if (!d.count(l)) d[l] = 0;
        if (!d.count(r)) d[r] = 0;
        if (!d.count(r + 1)) d[r + 1] = 0;
        
        d[l]++, d[r + 1]--;
    }
    for (auto it = d.begin(); it != d.end(); it++) {
        if (it == d.begin()) continue;
        auto& [_, cnt1] = *it;
        auto& [_1, cnt2] = *(prev(it));
        cnt1 += cnt2; 
    }
    auto get = [&](int x) -> int {
        if (d.count(x)) return d[x];
        if (d.count(x + 1)) return d[x + 1];
        if (d.count(x - 1)) return d[x - 1];
        return 0;
    };
    for (auto& [l, r]: e) {
        if (abs(get(l) - get(r)) >= p) cnt++;
    }
    cout << cnt;
    return 0;
}