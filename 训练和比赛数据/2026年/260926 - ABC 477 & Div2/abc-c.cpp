#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

string s, t;
vector<int> pos;
int n, m;

bool solve() {
    int l, r; cin >> l >> r;
    if (r - l + 1 < m) return 0;
    auto it1 = lower_bound(range(pos), l);
    // cout << "l:" << (it1 == pos.end() ? n : *it1) << " ";
    auto it2 = upper_bound(range(pos), r);
    // cout << "r:" << (it2 == pos.end() ? n : *it2) << " ";
    for (auto it = it1; it < it2; it++) {
        int& i = *it;
        if (i + m - 1 <= r) return 1;
    }
    return 0;
}

int main() {
    ios;
    int q; cin >> q;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    
    int i = 0;
    auto it = s.find(t, i);
    while (it != string::npos) {
        pos.push_back(it + 1);
        i = it + 1;
        it = s.find(t, i);
    }
    // cout << "pos:";
    // for (auto it = pos.begin(); it != pos.end(); it++)
    //     cout << *it << (it + 1 != pos.end() ? " " : "\n");
    while (q--) {
        cout << (solve() ? "Yes" : "No");
        if (q) cout << "\n";
    }
    return 0;
}