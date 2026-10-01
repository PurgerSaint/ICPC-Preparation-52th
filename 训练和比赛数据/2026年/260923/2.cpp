#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    ll cost = 0;
    int l = 1, r = n;
    vector<int> loc;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(' || (s[i] == '_' && loc.empty())) {
            loc.push_back(i);
        } else {
            cost += i - loc.back();
            loc.pop_back();
        }
    }
    return cost;
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