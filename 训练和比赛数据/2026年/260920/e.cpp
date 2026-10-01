#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    vector<int> mn;
    int nx = n + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < nx) {
            nx = a[i];
            mn.push_back(i);
        }
    }
    // for (auto it = mn.begin(); it != mn.end(); it++)
    //    cout << *it << (it + 1 != mn.end() ? " " : "\n");
    ll ans = 0;
    int px = 0;
    for (int i = 0; i < n; i++) {
        while (!mn.empty() && mn.back() < i) mn.pop_back();
        if (mn.empty()) break;
        if (a[i] > px) {
            cout << i << " " << mn.size() << "\n";
            px = a[i];
            ans += mn.size();
        }
    }
    cout << ans;
    return 0;
}