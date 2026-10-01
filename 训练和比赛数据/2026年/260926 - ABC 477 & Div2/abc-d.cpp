#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, q; cin >> n >> q;
    string s(n, 'a');
    vector<vector<int>> st(n);
    vector<char> op(q + 1, ' ');
    vector<int> b;
    for (int g = 1; g <= q; g++) {
        int k; cin >> k;
        if (k == 1) {
            int x; cin >> x;
            st[x - 1].push_back(g);
        } else {
            char c; cin >> c;
            b.push_back(g);
            op[g] = c;
        }
    }
    if (!b.empty()) {
        for (int k = 0; k < n; k++) {
            auto& pos = st[k];

            if (pos.size() % 2 == 0)
                pos.push_back(q + 1);
            
            int sz = pos.size();
            for (int i = sz - 1; i >= 0; i -= 2) {
                int& r = pos[i];
                int l = i == 0 ? 0 : pos[i - 1];
                auto it1 = upper_bound(range(b), l);
                auto it2 = lower_bound(range(b), r);
                if (it1 < it2) {
                    // cout << *(it2 - 1) << "\n";
                    s[k] = op[*(it2 - 1)];
                    break;
                }
            }
        }
    }
    cout << s;
    return 0;
}