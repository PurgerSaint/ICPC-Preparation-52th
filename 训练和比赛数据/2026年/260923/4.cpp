#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n), diff;
    for (int& t: a) cin >> t;
    for (int i = 1; i < n; i++)
        diff.push_back(abs(a[i] - a[i - 1]));
    sort(range(diff));
    diff.erase(unique(range(diff)), diff.end());
    // for (auto it = diff.begin(); it != diff.end(); it++)
    //     cout << *it << (it + 1 != diff.end() ? " " : "\n");
    auto it1 = lower_bound(range(diff), 1);
    auto it2 = lower_bound(range(diff), n - 1);
    if (it1 != diff.end() && it2 != diff.end() && it2 - it1 + 1 == n - 1) cout << "Jolly";
    else cout << "Not jolly";
    return 0;
}