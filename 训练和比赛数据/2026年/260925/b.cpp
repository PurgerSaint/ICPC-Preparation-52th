#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<int> a(n), cnt(105, 0);
    for (int& t: a) {
        cin >> t;
        cnt[t]++;
    }
    sort(range(a));
    a.erase(unique(range(a)), a.end());
    int sz = 0;
    while (sz < n) {
        for (auto it = a.rbegin(); it != a.rend(); it++) {
            if (cnt[*it]) {
                cout << *it;
                cnt[*it]--;
                sz++;
                if (sz < n) cout << " ";
            }
        }
    }
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}