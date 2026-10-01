#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; ll d; cin >> n >> d;
    vector<ll> a(n + 1), dis(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dis[i - 1] = a[i];
    }
    sort(range(dis));
    // dis.erase(unique(range(dis)), dis.end());
    vector<int> ans;
    int sz = dis.size();
    for (int i = 1; i <= n; i++) {
        ll& x = a[i];
        int pos = lower_bound(range(dis), x) - dis.begin();
        if (pos > 0 && dis[pos] - dis[pos - 1] < d) continue;
        if (pos + 1 < sz && dis[pos + 1] - dis[pos] < d) continue;
        ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << (it + 1 != ans.end() ? " " : "");
    return 0;
}